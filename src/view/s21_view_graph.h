#ifndef S21_SMARTCALC2_VIEW_GRAPH_H
#define S21_SMARTCALC2_VIEW_GRAPH_H

#include <QDialog>

#include "../controller/s21_controller.h"
#include "QVector"

namespace Ui {
class ViewGraph;
}

namespace s21 {

class ViewGraph : public QDialog {
  Q_OBJECT

 public:
  explicit ViewGraph(s21::Controller *controller, QWidget *parent = nullptr);
  void on_to_draw_button_clicked(double x_min, double x_max);

  ~ViewGraph();

 private:
  Ui::ViewGraph *ui;
  s21::Controller *s21_controller_;
  QVector<double> x, y;
};
}  // namespace s21
#endif  // S21_SMARTCALC2_VIEW_GRAPH_H
