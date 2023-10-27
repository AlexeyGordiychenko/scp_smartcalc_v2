#include "s21_controller.h"

#include "s21_model.h"

void s21::Controller::ParseExpression(const std::string& expression) {
  model_->ParseExpression(expression);
}
double s21::Controller::Calculate(double x) { return model_->Calculate(x); }
s21::CreditResult s21::Controller::CreditAnnuity(double principal, double term,
                                                 double interestRate) {
  return model_->CreditAnnuity(principal, term, interestRate);
}
s21::CreditResult s21::Controller::CreditDifferentiated(double principal,
                                                        double term,
                                                        double interestRate) {
  return model_->CreditDifferentiated(principal, term, interestRate);
}
