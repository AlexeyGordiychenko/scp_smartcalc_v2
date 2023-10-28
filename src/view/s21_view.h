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
  View(s21::Controller *controller, QWidget *parent = nullptr);
  ~View();

 private:
  Ui::View *ui;
  ViewGraph *s21_view_graph;
  s21::Controller *s21_controller_;

 private slots:
  void s21_button_to_result();
  void s21_button_to_result_with_bracket();
  void s21_clear_result();
  void s21_set_calc_result_invalid_x();
  void s21_set_calc_result_invalid_exp();
  void s21_set_calc_result_division_by_zero();
  void s21_calc_result();
  void s21_set_credit_result_invalid();
  void s21_set_credit_result(s21::CreditResult res);
  void s21_credit_result();
  QString get_format_string(double value);

 private:
  bool expEvaluated;
};
}  // namespace s21

#endif  // S21_SMARTCALC2_VIEW_H