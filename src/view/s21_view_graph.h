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
  // Constructors and the destructor
  explicit ViewGraph(s21::Controller *controller, QWidget *parent = nullptr);
  ViewGraph(const ViewGraph &) = delete;
  ViewGraph &operator=(const ViewGraph &) = delete;
  ViewGraph(ViewGraph &&) = delete;
  ViewGraph &operator=(ViewGraph &&) = delete;
  ~ViewGraph();

  // Main functions
  void Calculate(double x_min, double x_max);
  void AddSegment();
  void SetSettings();
  void Draw();

 private:
  Ui::ViewGraph *ui_;
  Controller *controller_;
  QVector<double> x_dots_, y_dots_;
};
}  // namespace s21
#endif  // S21_SMARTCALC2_VIEW_GRAPH_H
