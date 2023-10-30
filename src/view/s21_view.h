#ifndef S21_SMARTCALC2_VIEW_H
#define S21_SMARTCALC2_VIEW_H

#include <QDoubleValidator>
#include <QLocale>
#include <QMainWindow>

#include "../controller/s21_controller.h"
#include "s21_view_graph.h"

namespace Ui {
class View;
}

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  // Constructors and the destructor
  View(s21::Controller *controller, QWidget *parent = nullptr);
  View(const View &) = delete;
  View &operator=(const View &) = delete;
  View(View &&) = delete;
  View &operator=(View &&) = delete;
  ~View();

 private slots:
  // Main functions
  void ButtonToResult();
  void ButtonToResultWithBracket();
  void ClearResult();
  void SetCalcResultInvalidX();
  void SetCalcResultInvalidExp();
  void SetCalcResultDivisionByZero();
  void CalcExpression();
  QString GetFormatString(double value);

  // Bonus functions (credit)
  void SetCreditResultInvalid();
  void SetCreditResult(s21::CreditResult res);
  void CalcCredit();

 private:
  bool exp_evaluated_;
  Ui::View *ui_;
  ViewGraph *view_graph_;
  Controller *controller_;
};
}  // namespace s21
#endif  // S21_SMARTCALC2_VIEW_H