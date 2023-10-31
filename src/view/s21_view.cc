#include "s21_view.h"

#include "ui_s21_view.h"

s21::View::View(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);

  // radio buttons

  QObject::connect(ui_->calcMode, &QRadioButton::toggled,
                   [this](bool checked) { ui_->calcX->setVisible(checked); });
  QObject::connect(ui_->graphMode, &QRadioButton::toggled,
                   [this](bool checked) { ui_->graphX->setVisible(checked); });
  ui_->calcMode->setChecked(true);
  ui_->graphMode->setChecked(false);
  ui_->credit_annuity->setChecked(true);
  ui_->credit_differentiated->setChecked(false);

  // calc buttons

  connect(ui_->pushButton_0, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_1, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_2, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_3, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_4, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_5, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_6, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_7, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_8, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_9, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_mod, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_log, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(ButtonToResult()));
  connect(ui_->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(ButtonToResult()));
  connect(ui_->pushButton_div, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_mul, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(ButtonToResult()));
  connect(ui_->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(ButtonToResult()));
  connect(ui_->pushButton_point, SIGNAL(clicked()), this,
          SLOT(ButtonToResult()));
  connect(ui_->pushButton_pow, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(ButtonToResultWithBracket()));
  connect(ui_->pushButton_x, SIGNAL(clicked()), this, SLOT(ButtonToResult()));
  connect(ui_->pushButton_clear, SIGNAL(clicked()), this, SLOT(ClearResult()));
  connect(ui_->pushButton_equal, SIGNAL(clicked()), this, SLOT(Calculate()));

  // validation
  QDoubleValidator *x_validator = new QDoubleValidator(
      std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max(),
      std::numeric_limits<int>::max(), this);

  x_validator->setNotation(QDoubleValidator::StandardNotation);
  ui_->valueX->setValidator(x_validator);
  ui_->valueXMax->setValidator(x_validator);
  ui_->valueXMin->setValidator(x_validator);

  QDoubleValidator *credit_validator =
      new QDoubleValidator(0, std::numeric_limits<double>::max(),
                           std::numeric_limits<int>::max(), this);
  credit_validator->setNotation(QDoubleValidator::StandardNotation);
  ui_->credit_principal->setValidator(credit_validator);
  ui_->credit_rate->setValidator(credit_validator);
  ui_->credit_term->setValidator(credit_validator);

  // calc button
  connect(ui_->credit_calc, SIGNAL(clicked()), this, SLOT(CalculateCredit()));
}

s21::View::~View() { delete ui_; }

void s21::View::ButtonToResult(bool with_bracket) {
  if (exp_evaluated_) {
    ClearResult();
    exp_evaluated_ = false;
  };
  QPushButton *button = (QPushButton *)sender();

  QString new_label = ui_->expressionText->text() + button->text();

  ui_->expressionText->setText(new_label + (with_bracket ? "(" : ""));
}

void s21::View::ButtonToResultWithBracket() { ButtonToResult(true); }

void s21::View::ClearResult() { ui_->expressionText->setText(""); }

void s21::View::SetResultInvalidX() { SetResultError("Invalid 'x' value"); }

void s21::View::SetResultError(QString err) {
  ui_->expressionText->setText(err);
}

void s21::View::Calculate() {
  exp_evaluated_ = true;
  try {
    controller_->ParseExpression(ui_->expressionText->text().toStdString());
  } catch (const std::exception &e) {
    return SetResultError(e.what());
  }
  if (ui_->graphMode->isChecked()) {
    CalculateGraph();
  } else {
    CalculateExpression();
  }
}

void s21::View::CalculateGraph() {
  bool x_min_ok, x_max_ok;
  double x_value_min = ui_->valueXMin->text().toDouble(&x_min_ok);
  double x_value_max = ui_->valueXMax->text().toDouble(&x_max_ok);
  if (x_min_ok && x_max_ok && x_value_min <= x_value_max) {
    view_graph_ = new ViewGraph(controller_, this);
    view_graph_->Calculate(x_value_min, x_value_max);
    view_graph_->setWindowTitle("Graph for " + ui_->expressionText->text());
    view_graph_->show();
  } else {
    SetResultInvalidX();
  }
}

void s21::View::CalculateExpression() {
  double x_value = 0;
  bool x_ok = true;
  if (ui_->expressionText->text().contains("x", Qt::CaseInsensitive)) {
    x_value = ui_->valueX->text().toDouble(&x_ok);
  }
  if (x_ok) {
    double value = 0;
    bool calculated = false;
    try {
      value = controller_->Calculate(x_value);
      calculated = true;
    } catch (const std::exception &e) {
      SetResultError(e.what());
    }
    if (calculated) {
      QString numberResult = QString::number(value, 'g', 17);
      ui_->expressionText->setText(numberResult);
    }
  } else {
    SetResultInvalidX();
  }
}

QString s21::View::GetFormatString(double value) {
  return QString::number(value, 'f', 2);
}

void s21::View::SetCreditResultInvalid(QString err) {
  ui_->credit_monthly->setText(err);
  ui_->credit_over->setText(err);
  ui_->credit_total->setText(err);
}

void s21::View::SetCreditResult(s21::CreditResult res) {
  QString monthly_text = GetFormatString(res.monthly_start);
  if (res.monthly_start != res.monthly_end) {
    monthly_text += "..." + GetFormatString(res.monthly_end);
  }
  ui_->credit_monthly->setText(monthly_text);
  ui_->credit_over->setText(GetFormatString(res.over));
  ui_->credit_total->setText(GetFormatString(res.total));
}

void s21::View::CalculateCredit() {
  bool credit_principal_ok, credit_term_ok, credit_rate_ok;
  double credit_principal =
      ui_->credit_principal->text().toDouble(&credit_principal_ok);
  double credit_term = ui_->credit_term->text().toDouble(&credit_term_ok);
  double credit_rate = ui_->credit_rate->text().toDouble(&credit_rate_ok);
  s21::CreditResult res;
  if (credit_principal_ok && credit_term_ok && credit_rate_ok) {
    if (ui_->credit_annuity->isChecked()) {
      res = controller_->CreditAnnuity(credit_principal, credit_term,
                                       credit_rate);
    } else {
      res = controller_->CreditDifferentiated(credit_principal, credit_term,
                                              credit_rate);
    }
    SetCreditResult(res);
  } else {
    SetCreditResultInvalid();
  }
}
