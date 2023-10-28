#include "s21_view_graph.h"

#include "../thirdparty/qcustomplot.h"
#include "ui_s21_view_graph.h"

s21::ViewGraph::ViewGraph(s21::Controller* controller, QWidget* parent)
    : QDialog(parent), ui(new Ui::ViewGraph), s21_controller_(controller) {
  ui->setupUi(this);
}

s21::ViewGraph::~ViewGraph() { delete ui; }

void s21::ViewGraph::on_to_draw_button_clicked(double x_min, double x_max) {
  ui->widget->clearGraphs();

  double range_max = 1000000;
  if (x_max > range_max) x_max = range_max;
  if (x_min < -range_max) x_min = -range_max;

  double h = 0.1;
  for (double X = x_min; X < x_max; X += h) {
    x.push_back(X);
    double Y = s21_controller_->Calculate(X);
    y.push_back(Y);
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->rescaleAxes();
  ui->widget->replot();

  x.clear();
  y.clear();
}
