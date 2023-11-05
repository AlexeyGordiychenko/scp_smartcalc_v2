#include "scp_calc_tests.h"

TEST(scp_credit, 0) {
  scp::Model model;
  scp::CreditResult res = model.CreditAnnuity(91930155.62, 11, 15.04);
  EXPECT_DOUBLE_EQ(res.monthly_start, 1428069.86);
  EXPECT_DOUBLE_EQ(res.over, 96575065.90);
  EXPECT_DOUBLE_EQ(res.total, 188505221.52);
}

TEST(scp_credit, 1) {
  scp::Model model;
  scp::CreditResult res = model.CreditAnnuity(49042836.76, 10, 21.02);
  EXPECT_DOUBLE_EQ(res.monthly_start, 981180.99);
  EXPECT_DOUBLE_EQ(res.over, 68698882.04);
  EXPECT_DOUBLE_EQ(res.total, 117741718.80);
}

TEST(scp_credit, 2) {
  scp::Model model;
  scp::CreditResult res = model.CreditAnnuity(26162102.37, 48, 13.339);
  EXPECT_DOUBLE_EQ(res.monthly_start, 291313.65);
  EXPECT_DOUBLE_EQ(res.over, 141634560.03);
  EXPECT_DOUBLE_EQ(res.total, 167796662.40);
}

TEST(scp_credit, 3) {
  scp::Model model;
  scp::CreditResult res = model.CreditDifferentiated(91469864.23, 4, 14.719);
  EXPECT_NEAR(res.monthly_start, 3027576.28, 0.01);
  EXPECT_NEAR(res.monthly_end, 1928996.22, 0.01);
  EXPECT_NEAR(res.over, 27487875.69, 0.01);
  EXPECT_NEAR(res.total, 118957739.92, 0.01);
}

TEST(scp_credit, 4) {
  scp::Model model;
  scp::CreditResult res = model.CreditDifferentiated(41071637.5, 21, 3.12723);
  EXPECT_NEAR(res.monthly_start, 270016.40, 0.01);
  EXPECT_NEAR(res.monthly_end, 163407.43, 0.01);
  EXPECT_NEAR(res.over, 13539764.84, 0.01);
  EXPECT_NEAR(res.total, 54611402.34, 0.01);
}

TEST(scp_credit, 5) {
  scp::Model model;
  scp::CreditResult res = model.CreditDifferentiated(6659040.58, 3, 16.50267);
  EXPECT_NEAR(res.monthly_start, 276549.97, 0.01);
  EXPECT_NEAR(res.monthly_end, 187517.14, 0.01);
  EXPECT_NEAR(res.over, 1694167.55, 0.01);
  EXPECT_NEAR(res.total, 8353208.13, 0.01);
}
