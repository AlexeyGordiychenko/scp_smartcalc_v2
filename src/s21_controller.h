#ifndef S21_SMARTCALC2_CONTROLLER_H
#define S21_SMARTCALC2_CONTROLLER_H

#include "s21_model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model* model) : model_(model) {}
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(Controller&&) = delete;
  ~Controller() = default;
  void ParseExpression(const std::string& expression) {
    model_->ParseExpression(expression);
  }
  double Calculate(double x = 0) { return model_->Calculate(x); }

 private:
  Model* model_;
};
}  // namespace s21
#endif  // S21_SMARTCALC2_CONTROLLER_H()