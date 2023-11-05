#ifndef SCP_SMARTCALC2_VIEW_GRAPH_H
#define SCP_SMARTCALC2_VIEW_GRAPH_H

#include <QDialog>

#include "../controller/scp_controller.h"
#include "QVector"

namespace Ui {
class ViewGraph;
}

namespace scp {

class ViewGraph : public QDialog {
  Q_OBJECT

 public:
  // Constructors and the destructor
  explicit ViewGraph(scp::Controller *controller, QWidget *parent = nullptr);
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
}  // namespace scp
#endif  // SCP_SMARTCALC2_VIEW_GRAPH_H
