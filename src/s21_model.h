#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>

class Model {
 public:
  void ParseExpression(const std::string& expression) {
    std::queue<Token>().swap(rpn_queue_);
    std::stack<Token> op_stack;

    std::string token;
    TokenType prev_token_type = TokenType::kNone,
              curr_token_type = TokenType::kNone;
    auto expression_end = expression.end();
    auto it = expression.begin();
    while (it != expression_end) {
      curr_token_type = GetTokenType(it, expression_end);
      if (!IsValidToken(curr_token_type, prev_token_type)) {
        throw std::invalid_argument(invalid_exp_message_);
      }
      if (curr_token_type == TokenType::kCloseParenthesis) {
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
          throw std::invalid_argument(invalid_exp_message_);
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
          throw std::invalid_argument(invalid_exp_message_);
        }
        rpn_queue_.push(std::stod(token));
        it += end - i;
      } else if (curr_token_type == TokenType::kX) {
        rpn_queue_.push(curr_token_type);
      } else if (IsBinaryOperator(curr_token_type)) {
        if ((prev_token_type == TokenType::kNone ||
             prev_token_type == TokenType::kOpenParenthesis) &&
            IsPlusMinus(curr_token_type)) {
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
      } else {
        op_stack.push(curr_token_type);
      }
      prev_token_type = curr_token_type;
    }
    if (prev_token_type >= TokenType::kDiv) {
      throw std::invalid_argument(invalid_exp_message_);
    }

    while (!op_stack.empty()) {
      auto top = op_stack.top();
      TokenType* op = std::get_if<TokenType>(&top);

      if (op && *op == TokenType::kOpenParenthesis) {
        throw std::invalid_argument(invalid_exp_message_);
      }

      rpn_queue_.push(top);
      op_stack.pop();
    }
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
        } else if (IsFunction(*op)) {
          if (eval_stack.empty()) {
            throw std::invalid_argument(invalid_exp_message_);
          }
          double arg = eval_stack.top();
          eval_stack.pop();
          eval_stack.push(unary_functions_map_[*op](arg));
        } else {
          if (eval_stack.size() < 2) {
            throw std::invalid_argument(invalid_exp_message_);
          }
          double arg2 = eval_stack.top();
          eval_stack.pop();
          double arg1 = eval_stack.top();
          eval_stack.pop();
          eval_stack.push(binary_functions_map_[*op](arg1, arg2));
        }
      }
    }

    if (eval_stack.size() != 1) {
      throw std::invalid_argument(invalid_exp_message_);
    }

    return eval_stack.top();
  }

 private:
  enum class TokenType : char {
    kNone,
    kNumber,
    kX,
    kOpenParenthesis,
    kCloseParenthesis,
    kDiv,
    kMul,
    kExp,
    kPlus,
    kMinus,
    kMod,
    kSin,
    kCos,
    kTan,
    kAsin,
    kAcos,
    kAtan,
    kSqrt,
    kLn,
    kLog
  };

  using Token = std::variant<double, TokenType>;

  static const inline std::string invalid_exp_message_ = "Invalid expression";
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

  static inline std::unordered_map<std::string, TokenType> tokens_map_ = {
      {"(", TokenType::kOpenParenthesis},
      {")", TokenType::kCloseParenthesis},
      {"/", TokenType::kDiv},
      {"*", TokenType::kMul},
      {"^", TokenType::kExp},
      {"+", TokenType::kPlus},
      {"-", TokenType::kMinus},
      {"mod", TokenType::kMod},
      {"cos", TokenType::kCos},
      {"sin", TokenType::kSin},
      {"tan", TokenType::kTan},
      {"acos", TokenType::kAcos},
      {"asin", TokenType::kAsin},
      {"atan", TokenType::kAtan},
      {"sqrt", TokenType::kSqrt},
      {"ln", TokenType::kLn},
      {"log", TokenType::kLog},
      {"x", TokenType::kX}};

  static inline std::unordered_map<TokenType, std::function<double(double)>>
      unary_functions_map_ = {
          {TokenType::kSin, static_cast<double (*)(double)>(std::sin)},
          {TokenType::kCos, static_cast<double (*)(double)>(std::cos)},
          {TokenType::kTan, static_cast<double (*)(double)>(std::tan)},
          {TokenType::kAsin, static_cast<double (*)(double)>(std::asin)},
          {TokenType::kAcos, static_cast<double (*)(double)>(std::acos)},
          {TokenType::kAtan, static_cast<double (*)(double)>(std::atan)},
          {TokenType::kSqrt, static_cast<double (*)(double)>(std::sqrt)},
          {TokenType::kLn, static_cast<double (*)(double)>(std::log)},
          {TokenType::kLog, static_cast<double (*)(double)>(std::log10)}};
  static inline std::unordered_map<TokenType,
                                   std::function<double(double, double)>>
      binary_functions_map_ = {
          {TokenType::kPlus, Add},
          {TokenType::kMinus, Subtract},
          {TokenType::kMul, Multiply},
          {TokenType::kDiv, Divide},
          {TokenType::kMod, static_cast<double (*)(double, double)>(std::fmod)},
          {TokenType::kExp, static_cast<double (*)(double, double)>(std::pow)}};

  bool IsBinaryOperator(TokenType type) {
    return type >= TokenType::kDiv && type <= TokenType::kMod;
  }

  bool IsValue(TokenType type) {
    return type == TokenType::kNumber || type == TokenType::kX;
  }

  bool IsFunction(TokenType type) { return type >= TokenType::kSin; }

  bool IsPlusMinus(TokenType type) {
    return type == TokenType::kPlus || type == TokenType::kMinus;
  }

  int GetPriority(TokenType type) {
    int res = 2;
    if (IsPlusMinus(type)) {
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
    } else {
      std::string token(1, *it);
      if (std::isalpha(*it) && *it != 'x') {
        while (it++ != end && std::isalpha(*it) && *it != 'x') {
          token += *it;
        }
      } else {
        it++;
      }
      auto match = tokens_map_.find(token);
      if (match != tokens_map_.end()) {
        res = match->second;
      }
    }
    return res;
  }

  bool IsValidToken(TokenType ctt, TokenType ptt) {
    if (ctt == TokenType::kNone) return false;

    bool res = false;
    if (IsValue(ctt)) {
      // A number should be preceded by a binary operator or an opening
      // parenthesis.
      res = ptt == TokenType::kNone || IsBinaryOperator(ptt) ||
            ptt == TokenType::kOpenParenthesis;
    } else if (IsBinaryOperator(ctt)) {
      // A binary operator should be preceded by a number or a close
      // parenthesis.
      res = IsValue(ptt) || ptt == TokenType::kCloseParenthesis;
      if (!res && IsPlusMinus(ctt)) {
        // An unary operator can also be the first char or preceded by an
        // opening parenthesis
        res = ptt == TokenType::kNone || ptt == TokenType::kOpenParenthesis;
      }
    } else if (ctt == TokenType::kOpenParenthesis) {
      // An opening parenthesis should be preceded by any operator or another
      // opening parenthesis or can also be the first char
      // In other words by anything, except a value or a closing parenthesis
      res = !IsValue(ptt) && ptt != TokenType::kCloseParenthesis;
    } else if (ctt == TokenType::kCloseParenthesis) {
      // A closing parenthesis should be preceded by a number or another closing
      // parenthesis.
      res = IsValue(ptt) || ptt == TokenType::kCloseParenthesis;
    } else if (IsFunction(ctt)) {
      // A function should be preceded by a binary operator or an open
      // parenthesis or can also be the first char
      res = ptt == TokenType::kNone || IsBinaryOperator(ptt) ||
            ptt == TokenType::kOpenParenthesis;
    }
    return res;
  }
};
