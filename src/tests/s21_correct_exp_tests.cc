#include "s21_calc_tests.h"

TEST(s21_correct, 0) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("2+2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 4);
}

TEST(s21_correct, 1) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("3*5+15-4"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 26);
}

TEST(s21_correct, 2) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("4/2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0);
}

TEST(s21_correct, 3) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("10^2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 100);
}

TEST(s21_correct, 4) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(-1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), -1);
}

TEST(s21_correct, 5) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("+3"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 3);
}

TEST(s21_correct, 6) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("-3"));
  EXPECT_DOUBLE_EQ(model.Calculate(), -3);
}

TEST(s21_correct, 7) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("5mod2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 1);
}

TEST(s21_correct, 8) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("cos(0.7853981633974483)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7071067811865476);
}

TEST(s21_correct, 9) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sin(0.5235987755982988)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.49999999999999994);
}

TEST(s21_correct, 10) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("tan(0.7853981633974483)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999999999999999);
}

TEST(s21_correct, 11) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("acos(0.5)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0471975511965979);
}

TEST(s21_correct, 12) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("asin(0.5)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.5235987755982989);
}

TEST(s21_correct, 13) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("atan(1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(s21_correct, 14) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 4.0);
}

TEST(s21_correct, 15) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln(2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6931471805599453);
}

TEST(s21_correct, 16) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("log(10)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0);
}

TEST(s21_correct, 17) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(2+3)*(5-2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(s21_correct, 18) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("2*3^2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 18);
}

TEST(s21_correct, 19) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln(2^5)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.4657359027997265);
}

TEST(s21_correct, 20) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("2+2*3+(4/2)^2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 12.0);
}

TEST(s21_correct, 21) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("sin(0.5235987755982988)+cos(1.0471975511965979)-"
                            "tan(0.7853981633974483)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), -1.1102230246251565e-16);
}

TEST(s21_correct, 22) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16)+sqrt(9)*2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 10.0);
}

TEST(s21_correct, 23) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln(2)+log(10)-log(2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.3921171848959641);
}

TEST(s21_correct, 24) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(2+3)*(5-2)+(3+4)*(2-1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 22);
}

TEST(s21_correct, 25) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("23^2+45^2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 2554);
}

TEST(s21_correct, 26) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln(2^5)+log(10^2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.465735902799727);
}

TEST(s21_correct, 27) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("acos(0.5)+asin(0.5)+atan(1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.356194490192345);
}

TEST(s21_correct, 28) {
  Model model;
  EXPECT_TRUE(model.ParseExpression(
      "(2+sin(0.5235987755982988))*(2-cos(1.0471975511965979))"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.75);
}

TEST(s21_correct, 29) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16+9*2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.830951894845301);
}

TEST(s21_correct, 30) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("cos(0.5235987755982988)+sin(0.7853981633974483)*"
                            "tan(1.0471975511965979)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0907702751760278);
}

TEST(s21_correct, 31) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16+92)+45-2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 53.392304845413264);
}

TEST(s21_correct, 32) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln(2)+log(10)-acos(0.5)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6459496293633475);
}

TEST(s21_correct, 33) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(2+3)+((5-2)+(3+4)*(2-1))"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(s21_correct, 34) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("23^2+45^2-sqrt(9)mod16"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 2551.0);
}

TEST(s21_correct, 35) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("ln((2^3)^2)+log(10^2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 6.1588830833596715);
}

TEST(s21_correct, 36) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt((16+9)*2^3)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 14.142135623730951);
}

TEST(s21_correct, 37) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("asin(0.5)^2+atan(1)^2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.8910059528761227);
}

TEST(s21_correct, 38) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(2+sin(0.5235987755982988))*2"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.0);
}

TEST(s21_correct, 39) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16+9*2)*3"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 17.492855684535904);
}

TEST(s21_correct, 40) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("(2+3)*5+x-4mod2"));
  EXPECT_DOUBLE_EQ(model.Calculate(2896), 2921);
}

TEST(s21_correct, 41) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("sqrt(16)+cos(x)+sin(3.14159/2)+tan(3.14159/4)"));
  EXPECT_DOUBLE_EQ(model.Calculate(9339), 5.42235654692368);
}

TEST(s21_correct, 42) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("acos(1)+asin(1)+atan(1)+ln(1)+log(10)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.356194490192345);
}

TEST(s21_correct, 43) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("2^3*5+15-x+sqrt(16)"));
  EXPECT_DOUBLE_EQ(model.Calculate(8395), -8336.0);
}

TEST(s21_correct, 44) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("cos(0)+sin(3.14159/2)-tan(3.14159/x)+acos(1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(9977), 1.9996851167572804);
}

TEST(s21_correct, 45) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("asin(0)*atan(1)/5mod4+log(x)"));
  EXPECT_DOUBLE_EQ(model.Calculate(6371), 3.8042076050820413);
}

TEST(s21_correct, 46) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("sqrt(x)+cos(0)-sin(3.14159/2)*tan(3.14159/4)"));
  EXPECT_DOUBLE_EQ(model.Calculate(7522), 86.729465754981);
}

TEST(s21_correct, 47) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)+x"));
  EXPECT_DOUBLE_EQ(model.Calculate(3443), 3443.0);
}

TEST(s21_correct, 48) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("log(10)*2^3*5+x-x"));
  EXPECT_DOUBLE_EQ(model.Calculate(2065), 40.0);
}

TEST(s21_correct, 49) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16)modx+cos(0)+sin(3.14159/2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(4641), 5.99999999999912);
}

TEST(s21_correct, 50) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("tan(3.14159/4)+acos(1)-asin(0)*x"));
  EXPECT_DOUBLE_EQ(model.Calculate(4033), 0.9999986732059836);
}

TEST(s21_correct, 51) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("atan(1)+ln(1)*log(10)/x"));
  EXPECT_DOUBLE_EQ(model.Calculate(1924), 0.7853981633974483);
}

TEST(s21_correct, 52) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("x^3*5+15-x+sqrt(16)"));
  EXPECT_DOUBLE_EQ(model.Calculate(1810), 29648703209.0);
}

TEST(s21_correct, 53) {
  Model model;
  EXPECT_TRUE(
      model.ParseExpression("cos(x)-1modx+sin(3.14159/2)*tan(3.14159/4)"));
  EXPECT_DOUBLE_EQ(model.Calculate(3398), 0.359324287215802);
}

TEST(s21_correct, 54) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.0);
}

TEST(s21_correct, 55) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("log(10)*2^3*5+x-4"));
  EXPECT_DOUBLE_EQ(model.Calculate(162), 198.0);
}

TEST(s21_correct, 56) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("sqrt(16)-cos(0)+sin(3.14159/2)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.99999999999912);
}

TEST(s21_correct, 57) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("tan(3.14159/4)+acos(1)*asin(0)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999986732059836);
}

TEST(s21_correct, 58) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("atan(1)+ln(1)/log(10)"));
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(s21_correct, 59) {
  Model model;
  EXPECT_TRUE(model.ParseExpression("2^3*5+x-4+sqrt(16)"));
  EXPECT_DOUBLE_EQ(model.Calculate(4299), 4339.0);
}