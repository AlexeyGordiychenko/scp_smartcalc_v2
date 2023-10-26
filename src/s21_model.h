#include <charconv>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>

namespace s21 {

class Model {
 public:
  void ParseExpression(const std::string& expression) {
    ClearTheQueue();
    std::stack<Token> op_stack;
    TokenType prev_token_type = TokenType::kNone,
              curr_token_type = TokenType::kNone;
    auto expression_end = expression.end();
    auto it = expression.begin();

    while (SkipSpaces(it, expression_end)) {
      curr_token_type = GetTokenType(it, expression_end);

      if (!IsValidToken(curr_token_type, prev_token_type)) {
        ThrowInvalidExpression();
      }

      if (curr_token_type == TokenType::kCloseParenthesis) {
        HandleCloseParenthesis(op_stack);
      } else if (curr_token_type == TokenType::kNumber) {
        curr_token_type = TokenType::kNumber;
        it += ParseNumber(std::string(it, expression_end));
      } else if (curr_token_type == TokenType::kX) {
        rpn_queue_.push_back(curr_token_type);
      } else if (IsBinaryOperator(curr_token_type)) {
        HandleBinaryOperator(op_stack, curr_token_type, prev_token_type);
      } else {
        op_stack.push(curr_token_type);
      }

      prev_token_type = curr_token_type;
    }

    // If we have any operator at the end - it's an invalid expression
    if (prev_token_type >= TokenType::kDiv) {
      ThrowInvalidExpression();
    }

    // Move the remaining operators to the RPN queue
    MoveOperatorsFromStackToQueue(op_stack);
  }

  double Calculate(double x = 0) {
    std::stack<double> eval_stack;
    for (auto token : rpn_queue_) {
      if (auto val = std::get_if<double>(&token)) {
        eval_stack.push(*val);
      } else if (auto op = std::get_if<TokenType>(&token)) {
        if (*op == TokenType::kX) {
          eval_stack.push(x);
        } else if (IsFunction(*op)) {
          if (eval_stack.empty()) {
            ThrowInvalidExpression();
          }
          double arg = eval_stack.top();
          eval_stack.pop();
          eval_stack.push(unary_functions_map_[*op](arg));
        } else {
          if (eval_stack.size() < 2) {
            ThrowInvalidExpression();
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
      ThrowInvalidExpression();
    }

    return eval_stack.top();
  }

 private:
  // All possible token types, the order is important, because operators '>' '<'
  // are used in conditions
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
      throw std::domain_error("Division by zero");
    }
    return a / b;
  }

  std::vector<Token> rpn_queue_;

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
                         std::string::const_iterator& end) {
    TokenType res = TokenType::kNone;
    if (std::isdigit(*it) || *it == '.') {
      // If it's a digit, set the correct token type and exit the function,
      // the number will be parsed later in the ParseNumber function, called
      // from ParseExpression function
      res = TokenType::kNumber;
    } else {
      // Convert the first char to a string, if it's a letter then parse all the
      // consecutive letters (except 'x'), then compare the token to all
      // possible operators/functions
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

  void HandleCloseParenthesis(std::stack<Token>& op_stack) {
    // While the token at the top of the stack is not a left parenthesis,
    // pop the token-operators from the stack into the output queue.
    while (!op_stack.empty()) {
      auto top = op_stack.top();
      TokenType* op = std::get_if<TokenType>(&top);

      if (op && *op != TokenType::kOpenParenthesis) {
        rpn_queue_.push_back(top);
        op_stack.pop();
      } else {
        break;
      }
    }

    if (op_stack.empty()) {
      // Mismatched parentheses
      ThrowInvalidExpression();
    } else {
      // Pop the left parenthesis from the stack.
      op_stack.pop();
      // If there is a function token at the top of the stack, then pop the
      // function from the stack into the output queue
      if (!op_stack.empty()) {
        auto top = op_stack.top();
        TokenType* op = std::get_if<TokenType>(&top);

        if (op && IsFunction(*op)) {
          rpn_queue_.push_back(top);
          op_stack.pop();
        }
      }
    }
  }

  std::size_t ParseNumber(const std::string& expression) {
    double num;
    auto [p, ec] = std::from_chars(expression.data(),
                                   expression.data() + expression.size(), num);

    if (ec != std::errc()) {
      ThrowInvalidExpression();
    }

    rpn_queue_.push_back(num);
    return p - expression.data();
  }

  void HandleBinaryOperator(std::stack<Token>& op_stack, TokenType ctt,
                            TokenType ptt) {
    // If unary + or -, push 0 into the output queue
    if ((ptt == TokenType::kNone || ptt == TokenType::kOpenParenthesis) &&
        IsPlusMinus(ctt)) {
      rpn_queue_.push_back(0.0);
    }

    // While there is an token-operator O2 at the top of the stack, that has
    // greater or equal precedence than O1, pop O2 from the stack into the
    // output queue, push O1 onto the stack
    while (!op_stack.empty()) {
      auto top = op_stack.top();
      auto stack_priority = GetPriority(std::get<TokenType>(top));
      auto ctt_priority = GetPriority(ctt);
      // Exp has a right-to-left associativity, so we use '>' for it
      if ((ctt == TokenType::kExp) ? stack_priority > ctt_priority
                                   : stack_priority >= ctt_priority) {
        op_stack.pop();
        rpn_queue_.push_back(top);
      } else {
        break;
      }
    }
    op_stack.push(ctt);
  }

  void MoveOperatorsFromStackToQueue(std::stack<Token>& op_stack) {
    // At the end of the parsing if there are operators left in the stack, move
    // them all to the queue
    while (!op_stack.empty()) {
      auto top = op_stack.top();
      TokenType* op = std::get_if<TokenType>(&top);

      if (op && *op == TokenType::kOpenParenthesis) {
        ThrowInvalidExpression();
      }

      rpn_queue_.push_back(top);
      op_stack.pop();
    }
  }

  bool SkipSpaces(std::string::const_iterator& it,
                  std::string::const_iterator& end) {
    while (it != end && std::isspace(*it)) ++it;
    return it != end;
  }

  void ThrowInvalidExpression() {
    ClearTheQueue();
    throw std::invalid_argument(invalid_exp_message_);
  }

  void ClearTheQueue() {
    if (!rpn_queue_.empty()) rpn_queue_ = {};
  }
};
}  // namespace s21