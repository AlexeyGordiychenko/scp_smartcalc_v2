#ifndef S21_SMARTCALC2_CONTROLLER_H
#define S21_SMARTCALC2_CONTROLLER_H

#include <string>

#include "s21_credit.h"

namespace s21 {

class Model;

class Controller {
 public:
  Controller(Model* model) : model_(model) {}
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(Controller&&) = delete;
  ~Controller() = default;
  void ParseExpression(const std::string& expression);
  double Calculate(double x = 0);
  CreditResult CreditAnnuity(double principal, double term,
                             double interestRate);
  CreditResult CreditDifferentiated(double principal, double term,
                                    double interestRate);

 private:
  Model* model_;
};
}  // namespace s21
#endif  // S21_SMARTCALC2_CONTROLLER_H()