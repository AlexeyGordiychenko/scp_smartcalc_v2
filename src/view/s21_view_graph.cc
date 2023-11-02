#include "s21_view_graph.h"

#include "../thirdparty/qcustomplot.h"
#include "ui_s21_view_graph.h"

s21::ViewGraph::ViewGraph(s21::Controller* controller, QWidget* parent)
    : QDialog(parent), ui_(new Ui::ViewGraph), controller_(controller) {
  ui_->setupUi(this);
}

s21::ViewGraph::~ViewGraph() { delete ui_; }

void s21::ViewGraph::Calculate(double x_min, double x_max) {
  ui_->widget->clearGraphs();

  double range_max = 1000000;
  if (x_max > range_max) x_max = range_max;
  if (x_min < -range_max) x_min = -range_max;

  double h = 0.1, y_value = 0;
  if (x_max <= 10 && x_min >= -10) h = 0.01;
  for (auto x_value = x_min; x_value < x_max; x_value += h) {
    if (abs(x_value) < 1e-7) x_value = 0;
    bool calculated = true;
    try {
      y_value = controller_->Calculate(x_value);
    } catch (const std::exception& e) {
      calculated = false;
    }
    if (calculated && y_value <= range_max && y_value >= -range_max) {
      y_dots_.push_back(y_value);
      x_dots_.push_back(x_value);
    } else {
      AddSegment();
    }
  }
  AddSegment();
  SetSettings();
  Draw();
}

void s21::ViewGraph::AddSegment() {
  ui_->widget->addGraph();
  ui_->widget->graph()->addData(x_dots_, y_dots_);
  x_dots_.clear();
  y_dots_.clear();
}
void s21::ViewGraph::Draw() {
  ui_->widget->rescaleAxes();
  ui_->widget->replot();
}

void s21::ViewGraph::SetSettings() {
  ui_->widget->setInteraction(QCP::iRangeZoom, true);
  ui_->widget->setInteraction(QCP::iRangeDrag, true);
}
