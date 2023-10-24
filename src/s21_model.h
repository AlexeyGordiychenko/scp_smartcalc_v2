#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>

enum class TokenType : char {
  kNone,
  kNumber,
  kOpenParenthesis,
  kCloseParenthesis,
  kDiv,
  kMul,
  kExp,
  kPlus,
  kMinus,
  kMod,
  kCos,
  kSin,
  kTan,
  kAcos,
  kAsin,
  kAtan,
  kSqrt,
  kLn,
  kLog,
  kX
};

using Token = std::variant<double, TokenType>;

class Model {
 public:
  bool ParseExpression(const std::string& expression) {
    std::queue<Token>().swap(rpn_queue_);
    std::stack<Token> op_stack;

    std::string token;
    TokenType prev_token_type = TokenType::kNone,
              curr_token_type = TokenType::kNone;
    auto expression_end = expression.end();
    auto it = expression.begin();
    while (it != expression_end) {
      auto c = *it;
      curr_token_type = GetTokenType(it, expression_end);
      if (!IsValidToken(curr_token_type, prev_token_type)) {
        return false;
      }
      if (c == ')') {
        // A right parenthesis:
        // While the token at the top of the stack is not a left parenthesis,
        // pop the token-operators from the stack into the output queue.
        while (!op_stack.empty()) {
          auto top = op_stack.top();
          TokenType* op = std::get_if<TokenType>(&top);
          if (op && *op != TokenType::kOpenParenthesis) {
            rpn_queue_.push(top);
            op_stack.pop();
          } else {
            break;
          }
        }

        if (op_stack.empty()) {
          // Mismatched parentheses
          return false;
        } else {
          // Pop the left parenthesis from the stack.
          op_stack.pop();
          // If there is a function token at the top of the stack, then pop the
          // function from the stack into the output queue
          if (!op_stack.empty()) {
            auto top = op_stack.top();
            TokenType* op = std::get_if<TokenType>(&top);

            if (op && IsFunction(*op)) {
              rpn_queue_.push(top);
              op_stack.pop();
            }
          }
        }
        it++;
      } else if (curr_token_type == TokenType::kNumber) {
        curr_token_type = TokenType::kNumber;
        auto i = it - expression.begin();
        auto end = expression.find_first_not_of("0123456789.", i);
        if (end == std::string::npos) {
          end = expression.size();
        }
        token = expression.substr(i, end - i);
        if (token.back() == '.' ||
            std::count(token.begin(), token.end(), '.') > 1) {
          return false;
        }
        rpn_queue_.push(std::stod(token));
        it += end - i;
      } else if (curr_token_type == TokenType::kX) {
        rpn_queue_.push(curr_token_type);
        it++;
      } else if (IsOperator(curr_token_type)) {
        if ((prev_token_type == TokenType::kNone ||
             prev_token_type == TokenType::kOpenParenthesis) &&
            IsUnaryOperator(curr_token_type)) {
          rpn_queue_.push(0.0);
        }

        Token top;
        while (!op_stack.empty() &&
               GetPriority(std::get<TokenType>(top = op_stack.top())) >=
                   GetPriority(curr_token_type)) {
          op_stack.pop();
          rpn_queue_.push(top);
        }
        op_stack.push(curr_token_type);
        if (curr_token_type != TokenType::kMod) it++;
      } else {
        op_stack.push(curr_token_type);
        if (curr_token_type == TokenType::kOpenParenthesis) it++;
      }
      prev_token_type = curr_token_type;
    }

    if (prev_token_type >= TokenType::kPlus &&
        prev_token_type != TokenType::kX) {
      return false;
    }

    while (!op_stack.empty()) {
      auto top = op_stack.top();
      TokenType* op = std::get_if<TokenType>(&top);

      if (op && *op == TokenType::kOpenParenthesis) {
        return false;
      }

      rpn_queue_.push(top);
      op_stack.pop();
    }

    return true;
  }

  double Calculate(double x = 0) {
    std::stack<double> eval_stack;

    while (!rpn_queue_.empty()) {
      Token token = rpn_queue_.front();
      rpn_queue_.pop();

      if (auto val = std::get_if<double>(&token)) {
        eval_stack.push(*val);
      } else if (auto op = std::get_if<TokenType>(&token)) {
        if (*op == TokenType::kX) {
          eval_stack.push(x);
        } else if (*op >= TokenType::kCos) {
          if (eval_stack.empty()) {
            throw std::invalid_argument("Not enough arguments for function");
          }
          double arg = eval_stack.top();
          eval_stack.pop();
          eval_stack.push(unary_functions[*op](arg));
        } else {
          if (eval_stack.size() < 2) {
            throw std::invalid_argument("Not enough arguments for operator");
          }
          double arg2 = eval_stack.top();
          eval_stack.pop();
          double arg1 = eval_stack.top();
          eval_stack.pop();
          eval_stack.push(binary_functions[*op](arg1, arg2));
        }
      }
    }

    if (eval_stack.size() != 1) {
      throw std::logic_error("Invalid RPN expression");
    }

    return eval_stack.top();
  }

 private:
  static double Add(double a, double b) { return a + b; }

  static double Subtract(double a, double b) { return a - b; }

  static double Multiply(double a, double b) { return a * b; }

  static double Divide(double a, double b) {
    if (b == 0) {
      throw std::invalid_argument("Division by zero");
    }
    return a / b;
  }

  std::queue<Token> rpn_queue_;
  std::unordered_map<TokenType, std::function<double(double)>> unary_functions =
      {{TokenType::kSin, static_cast<double (*)(double)>(std::sin)},
       {TokenType::kCos, static_cast<double (*)(double)>(std::cos)},
       {TokenType::kTan, static_cast<double (*)(double)>(std::tan)},
       {TokenType::kAsin, static_cast<double (*)(double)>(std::asin)},
       {TokenType::kAcos, static_cast<double (*)(double)>(std::acos)},
       {TokenType::kAtan, static_cast<double (*)(double)>(std::atan)},
       {TokenType::kSqrt, static_cast<double (*)(double)>(std::sqrt)},
       {TokenType::kLn, static_cast<double (*)(double)>(std::log)},
       {TokenType::kLog, static_cast<double (*)(double)>(std::log10)}};
  std::unordered_map<TokenType, std::function<double(double, double)>>
      binary_functions = {
          {TokenType::kPlus, Add},
          {TokenType::kMinus, Subtract},
          {TokenType::kMul, Multiply},
          {TokenType::kDiv, Divide},
          {TokenType::kMod, static_cast<double (*)(double, double)>(std::fmod)},
          {TokenType::kExp, static_cast<double (*)(double, double)>(std::pow)}};

  std::vector<std::string> functions = {"sin",  "cos",  "tan", "asin", "acos",
                                        "atan", "sqrt", "ln",  "log",  "mod"};

  TokenType StringToTokenType(const std::string& str) {
    if (str == "sin") return TokenType::kSin;
    if (str == "cos") return TokenType::kCos;
    if (str == "tan") return TokenType::kTan;
    if (str == "asin") return TokenType::kAsin;
    if (str == "acos") return TokenType::kAcos;
    if (str == "atan") return TokenType::kAtan;
    if (str == "sqrt") return TokenType::kSqrt;
    if (str == "ln") return TokenType::kLn;
    if (str == "log") return TokenType::kLog;
    if (str == "mod") return TokenType::kMod;
    return TokenType::kNone;
  }

  bool IsOperator(TokenType type) {
    return type >= TokenType::kDiv && type <= TokenType::kMod;
  }

  bool IsValue(TokenType type) {
    return type == TokenType::kNumber || type == TokenType::kX;
  }

  bool IsFunction(TokenType type) {
    return type >= TokenType::kCos && type < TokenType::kX;
  }

  bool IsUnaryOperator(TokenType type) {
    return type == TokenType::kPlus || type == TokenType::kMinus;
  }

  int GetPriority(TokenType type) {
    int res = 2;
    if (IsUnaryOperator(type)) {
      res = 1;
    } else if (type == TokenType::kExp) {
      res = 3;
    } else if (type == TokenType::kOpenParenthesis ||
               type == TokenType::kCloseParenthesis) {
      res = -1;
    }
    return res;
  }

  TokenType GetTokenType(std::string::const_iterator& it,
                         std::string::const_iterator end) {
    TokenType res = TokenType::kNone;
    if (std::isdigit(*it)) {
      res = TokenType::kNumber;
    } else if (*it == 'x') {
      res = TokenType::kX;
    } else if (std::isalpha(*it)) {
      std::string expression(it, end);
      auto match = std::find_if(functions.begin(), functions.end(),
                                [&](const std::string& s) {
                                  return expression.substr(0, s.size()) == s;
                                });
      if (match != functions.end()) {
        it += match->size();
        res = StringToTokenType(*match);
      }
    } else {
      switch (*it) {
        case '(':
          res = TokenType::kOpenParenthesis;
          break;
        case ')':
          res = TokenType::kCloseParenthesis;
          break;
        case '/':
          res = TokenType::kDiv;
          break;
        case '*':
          res = TokenType::kMul;
          break;
        case '^':
          res = TokenType::kExp;
          break;
        case '+':
          res = TokenType::kPlus;
          break;
        case '-':
          res = TokenType::kMinus;
          break;
        case 'x':
          res = TokenType::kX;
          break;
      }
    }
    return res;
  }

  bool IsValidToken(TokenType ctt, TokenType ptt) {
    bool res = false;
    if (ctt == TokenType::kNone) {
      res = false;
    } else if (IsValue(ctt)) {
      // A number should be preceded by an operator or an opening parenthesis.
      res = ptt == TokenType::kNone || IsOperator(ptt) ||
            ptt == TokenType::kOpenParenthesis;
    } else if (IsOperator(ctt)) {
      // An operator should be preceded by a number or a close parenthesis.
      res = IsValue(ptt) || ptt == TokenType::kCloseParenthesis;
      if (!res && IsUnaryOperator(ctt)) {
        // A unary operator can also be the first char or preceded by an
        // opening parenthesis
        res = ptt == TokenType::kNone || ptt == TokenType::kOpenParenthesis;
      }
    } else if (ctt == TokenType::kOpenParenthesis) {
      // An opening parenthesis should be preceded by an operator or another
      // opening parenthesis.
      res = ptt == TokenType::kNone || IsOperator(ptt) || IsFunction(ptt) ||
            ptt == TokenType::kOpenParenthesis;
    } else if (ctt == TokenType::kCloseParenthesis) {
      // A closing parenthesis should be preceded by a number or another
      // closing parenthesis.
      res = IsValue(ptt) || ptt == TokenType::kCloseParenthesis;
    } else if (IsFunction(ctt)) {
      // A function should be preceded by a operator or an open parenthesis.
      res = ptt == TokenType::kNone || IsOperator(ptt) ||
            ptt == TokenType::kOpenParenthesis;
    }
    return res;
  }
};
