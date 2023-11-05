#ifndef SCP_SMARTCALC2_CONTROLLER_H
#define SCP_SMARTCALC2_CONTROLLER_H

#include <string>

#include "../credit/scp_credit.h"

namespace scp {

class Model;

class Controller {
 public:
  // Constructors and the destructor
  Controller(Model* model) : model_(model) {}
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(Controller&&) = delete;
  ~Controller() = default;

  // Main functions
  void ParseExpression(const std::string& expression);
  double Calculate(double x = 0);

  // Bonus functions (credit)
  CreditResult CreditAnnuity(double principal, double term,
                             double interestRate);
  CreditResult CreditDifferentiated(double principal, double term,
                                    double interestRate);

 private:
  Model* model_;
};
}  // namespace scp
#endif  // SCP_SMARTCALC2_CONTROLLER_H