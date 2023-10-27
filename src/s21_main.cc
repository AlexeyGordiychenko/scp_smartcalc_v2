#include <QApplication>

#include "s21_controller.h"
#include "s21_model.h"
#include "s21_view.h"

int main(int argc, char *argv[]) {
  QLocale::setDefault(QLocale::C);
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  s21::View w(&controller);
  w.show();
  return a.exec();
}
