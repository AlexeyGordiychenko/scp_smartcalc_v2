#include "scp_controller.h"

#include "../model/scp_model.h"

void scp::Controller::ParseExpression(const std::string& expression) {
  model_->ParseExpression(expression);
}

double scp::Controller::Calculate(double x) { return model_->Calculate(x); }

scp::CreditResult scp::Controller::CreditAnnuity(double principal, double term,
                                                 double interestRate) {
  return model_->CreditAnnuity(principal, term, interestRate);
}

scp::CreditResult scp::Controller::CreditDifferentiated(double principal,
                                                        double term,
                                                        double interestRate) {
  return model_->CreditDifferentiated(principal, term, interestRate);
}
