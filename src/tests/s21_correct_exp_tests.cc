#include "s21_calc_tests.h"

TEST(s21_correct, 0) {
  s21::Model model;
  model.ParseExpression("2+2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 4);
}

TEST(s21_correct, 1) {
  s21::Model model;
  model.ParseExpression("3*5+15-4");
  EXPECT_DOUBLE_EQ(model.Calculate(), 26);
}

TEST(s21_correct, 2) {
  s21::Model model;
  model.ParseExpression("4/2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0);
}

TEST(s21_correct, 3) {
  s21::Model model;
  model.ParseExpression("10^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 100);
}

TEST(s21_correct, 4) {
  s21::Model model;
  model.ParseExpression("(-1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1);
}

TEST(s21_correct, 5) {
  s21::Model model;
  model.ParseExpression("+3");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3);
}

TEST(s21_correct, 6) {
  s21::Model model;
  model.ParseExpression("-3");
  EXPECT_DOUBLE_EQ(model.Calculate(), -3);
}

TEST(s21_correct, 7) {
  s21::Model model;
  model.ParseExpression("5mod2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1);
}

TEST(s21_correct, 8) {
  s21::Model model;
  model.ParseExpression("cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7071067811865476);
}

TEST(s21_correct, 9) {
  s21::Model model;
  model.ParseExpression("sin(0.5235987755982988)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.49999999999999994);
}

TEST(s21_correct, 10) {
  s21::Model model;
  model.ParseExpression("tan(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999999999999999);
}

TEST(s21_correct, 11) {
  s21::Model model;
  model.ParseExpression("acos(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0471975511965979);
}

TEST(s21_correct, 12) {
  s21::Model model;
  model.ParseExpression("asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.5235987755982989);
}

TEST(s21_correct, 13) {
  s21::Model model;
  model.ParseExpression("atan(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(s21_correct, 14) {
  s21::Model model;
  model.ParseExpression("sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 4.0);
}

TEST(s21_correct, 15) {
  s21::Model model;
  model.ParseExpression("ln(2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6931471805599453);
}

TEST(s21_correct, 16) {
  s21::Model model;
  model.ParseExpression("log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0);
}

TEST(s21_correct, 17) {
  s21::Model model;
  model.ParseExpression("(2+3)*(5-2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(s21_correct, 18) {
  s21::Model model;
  model.ParseExpression("2*3^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 18);
}

TEST(s21_correct, 19) {
  s21::Model model;
  model.ParseExpression("ln(2^5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.4657359027997265);
}

TEST(s21_correct, 20) {
  s21::Model model;
  model.ParseExpression("2+2*3+(4/2)^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 12.0);
}

TEST(s21_correct, 21) {
  s21::Model model;
  model.ParseExpression(
      "sin(0.5235987755982988)+cos(1.0471975511965979)-tan(0."
      "7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1.1102230246251565e-16);
}

TEST(s21_correct, 22) {
  s21::Model model;
  model.ParseExpression("sqrt(16)+sqrt(9)*2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 10.0);
}

TEST(s21_correct, 23) {
  s21::Model model;
  model.ParseExpression("ln(2)+log(10)-log(2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.3921171848959641);
}

TEST(s21_correct, 24) {
  s21::Model model;
  model.ParseExpression("(2+3)*(5-2)+(3+4)*(2-1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 22);
}

TEST(s21_correct, 25) {
  s21::Model model;
  model.ParseExpression("23^2+45^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2554);
}

TEST(s21_correct, 26) {
  s21::Model model;
  model.ParseExpression("ln(2^5)+log(10^2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.465735902799727);
}

TEST(s21_correct, 27) {
  s21::Model model;
  model.ParseExpression("acos(0.5)+asin(0.5)+atan(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.356194490192345);
}

TEST(s21_correct, 28) {
  s21::Model model;
  model.ParseExpression(
      "(2+sin(0.5235987755982988))*(2-cos(1.0471975511965979))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.75);
}

TEST(s21_correct, 29) {
  s21::Model model;
  model.ParseExpression("sqrt(16+9*2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.830951894845301);
}

TEST(s21_correct, 30) {
  s21::Model model;
  model.ParseExpression(
      "cos(0.5235987755982988)+sin(0.7853981633974483)*tan(1."
      "0471975511965979)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0907702751760278);
}

TEST(s21_correct, 31) {
  s21::Model model;
  model.ParseExpression("sqrt(16+92)+45-2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 53.392304845413264);
}

TEST(s21_correct, 32) {
  s21::Model model;
  model.ParseExpression("ln(2)+log(10)-acos(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6459496293633475);
}

TEST(s21_correct, 33) {
  s21::Model model;
  model.ParseExpression("(2+3)+((5-2)+(3+4)*(2-1))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(s21_correct, 34) {
  s21::Model model;
  model.ParseExpression("23^2+45^2-sqrt(9)mod16");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2551.0);
}

TEST(s21_correct, 35) {
  s21::Model model;
  model.ParseExpression("ln((2^3)^2)+log(10^2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6.1588830833596715);
}

TEST(s21_correct, 36) {
  s21::Model model;
  model.ParseExpression("sqrt((16+9)*2^3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 14.142135623730951);
}

TEST(s21_correct, 37) {
  s21::Model model;
  model.ParseExpression("asin(0.5)^2+atan(1)^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.8910059528761227);
}

TEST(s21_correct, 38) {
  s21::Model model;
  model.ParseExpression("(2+sin(0.5235987755982988))*2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.0);
}

TEST(s21_correct, 39) {
  s21::Model model;
  model.ParseExpression("sqrt(16+9*2)*3");
  EXPECT_DOUBLE_EQ(model.Calculate(), 17.492855684535904);
}

TEST(s21_correct, 40) {
  s21::Model model;
  model.ParseExpression("(2+3)*5+x-4mod2");
  EXPECT_DOUBLE_EQ(model.Calculate(2896), 2921);
}

TEST(s21_correct, 41) {
  s21::Model model;
  model.ParseExpression("sqrt(16)+cos(x)+sin(3.14159/2)+tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(9339), 5.42235654692368);
}

TEST(s21_correct, 42) {
  s21::Model model;
  model.ParseExpression("acos(1)+asin(1)+atan(1)+ln(1)+log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.356194490192345);
}

TEST(s21_correct, 43) {
  s21::Model model;
  model.ParseExpression("2^3*5+15-x+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(8395), -8336.0);
}

TEST(s21_correct, 44) {
  s21::Model model;
  model.ParseExpression("cos(0)+sin(3.14159/2)-tan(3.14159/X)+acos(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(9977), 1.9996851167572804);
}

TEST(s21_correct, 45) {
  s21::Model model;
  model.ParseExpression("asin(0)*atan(1)/5mod4+log(x)");
  EXPECT_DOUBLE_EQ(model.Calculate(6371), 3.8042076050820413);
}

TEST(s21_correct, 46) {
  s21::Model model;
  model.ParseExpression("sqrt(x)+cos(0)-sin(3.14159/2)*tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(7522), 86.729465754981);
}

TEST(s21_correct, 47) {
  s21::Model model;
  model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)+x");
  EXPECT_DOUBLE_EQ(model.Calculate(3443), 3443.0);
}

TEST(s21_correct, 48) {
  s21::Model model;
  model.ParseExpression("log(10)*2^3*5+x-X");
  EXPECT_DOUBLE_EQ(model.Calculate(2065), 40.0);
}

TEST(s21_correct, 49) {
  s21::Model model;
  model.ParseExpression("sqrt(16)modx+cos(0)+sin(3.14159/2)");
  EXPECT_DOUBLE_EQ(model.Calculate(4641), 5.99999999999912);
}

TEST(s21_correct, 50) {
  s21::Model model;
  model.ParseExpression("tan(3.14159/4)+acos(1)-asin(0)*x");
  EXPECT_DOUBLE_EQ(model.Calculate(4033), 0.9999986732059836);
}

TEST(s21_correct, 51) {
  s21::Model model;
  model.ParseExpression("atan(1)+ln(1)*log(10)/x");
  EXPECT_DOUBLE_EQ(model.Calculate(1924), 0.7853981633974483);
}

TEST(s21_correct, 52) {
  s21::Model model;
  model.ParseExpression("x^3*5+15-x+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(1810), 29648703209.0);
}

TEST(s21_correct, 53) {
  s21::Model model;
  model.ParseExpression("cos(X)-1modx+sin(3.14159/2)*tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(3398), 0.359324287215802);
}

TEST(s21_correct, 54) {
  s21::Model model;
  model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.0);
}

TEST(s21_correct, 55) {
  s21::Model model;
  model.ParseExpression("log(10)*2^3*5+x-4");
  EXPECT_DOUBLE_EQ(model.Calculate(162), 198.0);
}

TEST(s21_correct, 56) {
  s21::Model model;
  model.ParseExpression("sqrt(16)-cos(0)+sin(3.14159/2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.99999999999912);
}

TEST(s21_correct, 57) {
  s21::Model model;
  model.ParseExpression("tan(3.14159/4)+acos(1)*asin(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999986732059836);
}

TEST(s21_correct, 58) {
  s21::Model model;
  model.ParseExpression("atan(1)+ln(1)/log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(s21_correct, 59) {
  s21::Model model;
  model.ParseExpression("2^3*5+x-4+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(4299), 4339.0);
}

TEST(s21_correct, 60) {
  s21::Model model;
  model.ParseExpression("( 2 + 3 ) * 5 + x - 4  mod  2");
  EXPECT_DOUBLE_EQ(model.Calculate(2896), 2921);
}

TEST(s21_correct, 61) {
  s21::Model model;
  model.ParseExpression(" X ^ 3 * 5+15-x+sqrt(16) ");
  EXPECT_DOUBLE_EQ(model.Calculate(1810), 29648703209.0);
}

TEST(s21_correct, 62) {
  s21::Model model;
  model.ParseExpression("2 ^ 2 ^ 3 ");
  EXPECT_DOUBLE_EQ(model.Calculate(), 256);
}

TEST(s21_correct, 63) {
  s21::Model model;
  model.ParseExpression("(5+2.3e4)/(3.5-1.2e2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -197.46781115879827);
}

TEST(s21_correct, 64) {
  s21::Model model;
  model.ParseExpression("(4.5e3+2)*(6.7e2-3.2e-4)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3016338.55936);
}

TEST(s21_correct, 65) {
  s21::Model model;
  model.ParseExpression("(2.1e5^3)/(x-2.3e2)");
  EXPECT_DOUBLE_EQ(model.Calculate(6550), 1465348101265.8228);
}

TEST(s21_correct, 66) {
  s21::Model model;
  model.ParseExpression("(7.6e3mod5)+(3.4e4mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.0);
}

TEST(s21_correct, 67) {
  s21::Model model;
  model.ParseExpression("sin(0.5235987755982988)+cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.2071067811865475);
}

TEST(s21_correct, 68) {
  s21::Model model;
  model.ParseExpression("tan(1.0471975511965976)-sin(1.5707963267948966)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7320508075688767);
}

TEST(s21_correct, 69) {
  s21::Model model;
  model.ParseExpression("asin(1)+acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.141592653589793);
}

TEST(s21_correct, 70) {
  s21::Model model;
  model.ParseExpression("atan(1)-asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.26179938779914935);
}

TEST(s21_correct, 71) {
  s21::Model model;
  model.ParseExpression("ln(2.3e+4)+log(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 13.924063087192078);
}

TEST(s21_correct, 72) {
  s21::Model model;
  model.ParseExpression("(sin(0.7853981633974483)+3.4e2)*(log(100)^3)/(xmod3)");
  EXPECT_DOUBLE_EQ(model.Calculate(5710), 2725.6568542494924);
}

TEST(s21_correct, 73) {
  s21::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(5))");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1428.0231519359106);
}

TEST(s21_correct, 74) {
  s21::Model model;
  model.ParseExpression(
      "(tan(1.0471975511965976)+1.2e-2)*(2.3e4^2)/(5mod3)+4.8e+4");
  EXPECT_DOUBLE_EQ(model.Calculate(), 461349438.60196793);
}

TEST(s21_correct, 75) {
  s21::Model model;
  model.ParseExpression("asin(0.5)+(4.5e-3*ln(2))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.5267179379108187);
}

TEST(s21_correct, 76) {
  s21::Model model;
  model.ParseExpression("(atan(1)+3.4e4)*(2.3e2^3)/(7mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 413687555939.45404);
}

TEST(s21_correct, 77) {
  s21::Model model;
  model.ParseExpression("ln(7.6e3)+log(100)*cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 10.350117088647519);
}

TEST(s21_correct, 78) {
  s21::Model model;
  model.ParseExpression(
      "(sin(0.5235987755982988)+2.1e5)*(3.4e4^2)/(50e-1mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 242760578000000.0);
}

TEST(s21_correct, 79) {
  s21::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(4.5e3))");
  EXPECT_DOUBLE_EQ(model.Calculate(), -272.377166514941);
}

TEST(s21_correct, 80) {
  s21::Model model;
  model.ParseExpression("(tan(0.7853981633974483)+1.2e2)*(7.6e3^2)/(3mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6988960000.0);
}

TEST(s21_correct, 81) {
  s21::Model model;
  model.ParseExpression("asin(0.5)+(2.1e5*ln(2))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 145561.4315163641);
}

TEST(s21_correct, 82) {
  s21::Model model;
  model.ParseExpression("(atan(1)+6.7e-2)*(3.4e+4^3)/(7mod3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 33502657414173.305);
}

TEST(s21_correct, 83) {
  s21::Model model;
  model.ParseExpression("(x+2.3e4)/(X-1.2e2)+1.1e-1^(2*1.0471975511965976)");
  EXPECT_DOUBLE_EQ(model.Calculate(8106), 3.9048905738199187);
}

TEST(s21_correct, 84) {
  s21::Model model;
  model.ParseExpression(
      "(4.5e3+2)*(6.7e2-3.2e4)+sin(20.943951023931955)+cos(41.88790204786391)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -141047659.63397458);
}

TEST(s21_correct, 85) {
  s21::Model model;
  model.ParseExpression("(2.1e5^3)/(x-2.3e2)+tan(62.831853071795855)");
  EXPECT_DOUBLE_EQ(model.Calculate(1580), 6860000000000.0);
}

TEST(s21_correct, 86) {
  s21::Model model;
  model.ParseExpression("(7.6e3mod5)+(3.4e4mod2)-asin(1)-acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -3.141592653589793);
}

TEST(s21_correct, 87) {
  s21::Model model;
  model.ParseExpression(
      "sin(0.5235987755982988)+cos(0.7853981633974483)-atan(1)+acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.9925049445839957);
}

TEST(s21_correct, 88) {
  s21::Model model;
  model.ParseExpression(
      "tan(1.0471975511965976)-sin(1.5707963267948966)+ln(2.3e4)-log(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6.894486710199372);
}

TEST(s21_correct, 89) {
  s21::Model model;
  model.ParseExpression(
      "(sin(0.7853981633974483)+3.4e2)*(log(100)^3)/"
      "(7mod3)+8.4e2^(1.5707963267948966)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 41940.20011530107);
}

TEST(s21_correct, 90) {
  s21::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(5))+tan(62.831853071795855)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1428.0231519359106);
}

TEST(s21_correct, 91) {
  s21::Model model;
  model.ParseExpression(
      "(tan(1.0471975511965976)+1.2e2)*(2.3e4^2)/(5mod3)+asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 32198127439.12557);
}

TEST(s21_correct, 92) {
  s21::Model model;
  model.ParseExpression("(atan(1)+3.4e4)*(2.3e2^3)/(7mod2)+ln(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 413687555948.38995);
}

TEST(s21_correct, 93) {
  s21::Model model;
  model.ParseExpression("(1.2e1 * 2) + (2.1e2 / 8.1e0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 49.925925925925924);
}

TEST(s21_correct, 94) {
  s21::Model model;
  model.ParseExpression("1/x");
  EXPECT_THROW(model.Calculate(), std::domain_error);
  EXPECT_DOUBLE_EQ(model.Calculate(2), 0.5);
}
