#ifndef SCP_SMARTCALC2_VIEW_H
#define SCP_SMARTCALC2_VIEW_H

#include <QDoubleValidator>
#include <QLocale>
#include <QMainWindow>

#include "../controller/scp_controller.h"
#include "scp_view_graph.h"

namespace Ui {
class View;
}

namespace scp {
class View : public QMainWindow {
  Q_OBJECT

 public:
  // Constructors and the destructor
  View(scp::Controller *controller, QWidget *parent = nullptr);
  View(const View &) = delete;
  View &operator=(const View &) = delete;
  View(View &&) = delete;
  View &operator=(View &&) = delete;
  ~View();

 private slots:
  // Main functions
  void ButtonToResult(bool with_bracket = false);
  void ButtonToResultWithBracket();
  void ClearResult();
  void SetResultInvalidX();
  void SetResultError(QString err);
  void Calculate();
  void CalculateGraph();
  void CalculateExpression();
  QString GetFormatString(double value);

  // Bonus functions (credit)
  void SetCreditResultInvalid(QString err = "Invalid input");
  void SetCreditResult(scp::CreditResult res);
  void CalculateCredit();

 private:
  bool exp_evaluated_;
  Ui::View *ui_;
  ViewGraph *view_graph_;
  Controller *controller_;
};
}  // namespace scp
#endif  // SCP_SMARTCALC2_VIEW_H