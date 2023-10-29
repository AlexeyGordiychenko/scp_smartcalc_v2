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

  double h = 0.1, y_value = 0;
  if (x_max <= 100 && x_min >= -100) h = 0.01;
  for (auto x_value = x_min; x_value < x_max; x_value += h) {
    if (abs(x_value) < 1e-7) x_value = 0;
    bool calculated = true;
    try {
      y_value = s21_controller_->Calculate(x_value);
    } catch (const std::exception& e) {
      calculated = false;
    }
    if (calculated && y_value <= range_max && y_value >= -range_max) {
      y.push_back(y_value);
      x.push_back(x_value);
    } else {
      // Add the previous segment to the graph
      ui->widget->addGraph();
      ui->widget->graph()->addData(x, y);
      // Start a new segment
      x.clear();
      y.clear();
    }
  }

  ui->widget->addGraph();
  ui->widget->graph()->addData(x, y);

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  ui->widget->rescaleAxes();
  ui->widget->replot();

  x.clear();
  y.clear();
}
