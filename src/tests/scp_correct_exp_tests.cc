#include "scp_calc_tests.h"

TEST(scp_correct, 0) {
  scp::Model model;
  model.ParseExpression("2+2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 4);
}

TEST(scp_correct, 1) {
  scp::Model model;
  model.ParseExpression("3*5+15-4");
  EXPECT_DOUBLE_EQ(model.Calculate(), 26);
}

TEST(scp_correct, 2) {
  scp::Model model;
  model.ParseExpression("4/2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0);
}

TEST(scp_correct, 3) {
  scp::Model model;
  model.ParseExpression("10^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 100);
}

TEST(scp_correct, 4) {
  scp::Model model;
  model.ParseExpression("(-1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1);
}

TEST(scp_correct, 5) {
  scp::Model model;
  model.ParseExpression("+3");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3);
}

TEST(scp_correct, 6) {
  scp::Model model;
  model.ParseExpression("-3");
  EXPECT_DOUBLE_EQ(model.Calculate(), -3);
}

TEST(scp_correct, 7) {
  scp::Model model;
  model.ParseExpression("5mod2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1);
}

TEST(scp_correct, 8) {
  scp::Model model;
  model.ParseExpression("cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7071067811865476);
}

TEST(scp_correct, 9) {
  scp::Model model;
  model.ParseExpression("sin(0.5235987755982988)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.49999999999999994);
}

TEST(scp_correct, 10) {
  scp::Model model;
  model.ParseExpression("tan(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999999999999999);
}

TEST(scp_correct, 11) {
  scp::Model model;
  model.ParseExpression("acos(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0471975511965979);
}

TEST(scp_correct, 12) {
  scp::Model model;
  model.ParseExpression("asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.5235987755982989);
}

TEST(scp_correct, 13) {
  scp::Model model;
  model.ParseExpression("atan(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(scp_correct, 14) {
  scp::Model model;
  model.ParseExpression("sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 4.0);
}

TEST(scp_correct, 15) {
  scp::Model model;
  model.ParseExpression("ln(2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6931471805599453);
}

TEST(scp_correct, 16) {
  scp::Model model;
  model.ParseExpression("log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.0);
}

TEST(scp_correct, 17) {
  scp::Model model;
  model.ParseExpression("(2+3)*(5-2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(scp_correct, 18) {
  scp::Model model;
  model.ParseExpression("2*3^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 18);
}

TEST(scp_correct, 19) {
  scp::Model model;
  model.ParseExpression("ln(2^5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.4657359027997265);
}

TEST(scp_correct, 20) {
  scp::Model model;
  model.ParseExpression("2+2*3+(4/2)^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 12.0);
}

TEST(scp_correct, 21) {
  scp::Model model;
  model.ParseExpression(
      "sin(0.5235987755982988)+cos(1.0471975511965979)-tan(0."
      "7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1.1102230246251565e-16);
}

TEST(scp_correct, 22) {
  scp::Model model;
  model.ParseExpression("sqrt(16)+sqrt(9)*2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 10.0);
}

TEST(scp_correct, 23) {
  scp::Model model;
  model.ParseExpression("ln(2)+log(10)-log(2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.3921171848959641);
}

TEST(scp_correct, 24) {
  scp::Model model;
  model.ParseExpression("(2+3)*(5-2)+(3+4)*(2-1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 22);
}

TEST(scp_correct, 25) {
  scp::Model model;
  model.ParseExpression("23^2+45^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2554);
}

TEST(scp_correct, 26) {
  scp::Model model;
  model.ParseExpression("ln(2^5)+log(10^2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.465735902799727);
}

TEST(scp_correct, 27) {
  scp::Model model;
  model.ParseExpression("acos(0.5)+asin(0.5)+atan(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.356194490192345);
}

TEST(scp_correct, 28) {
  scp::Model model;
  model.ParseExpression(
      "(2+sin(0.5235987755982988))*(2-cos(1.0471975511965979))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.75);
}

TEST(scp_correct, 29) {
  scp::Model model;
  model.ParseExpression("sqrt(16+9*2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.830951894845301);
}

TEST(scp_correct, 30) {
  scp::Model model;
  model.ParseExpression(
      "cos(0.5235987755982988)+sin(0.7853981633974483)*tan(1."
      "0471975511965979)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2.0907702751760278);
}

TEST(scp_correct, 31) {
  scp::Model model;
  model.ParseExpression("sqrt(16+92)+45-2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 53.392304845413264);
}

TEST(scp_correct, 32) {
  scp::Model model;
  model.ParseExpression("ln(2)+log(10)-acos(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.6459496293633475);
}

TEST(scp_correct, 33) {
  scp::Model model;
  model.ParseExpression("(2+3)+((5-2)+(3+4)*(2-1))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 15);
}

TEST(scp_correct, 34) {
  scp::Model model;
  model.ParseExpression("23^2+45^2-sqrt(9)mod16");
  EXPECT_DOUBLE_EQ(model.Calculate(), 2551.0);
}

TEST(scp_correct, 35) {
  scp::Model model;
  model.ParseExpression("ln((2^3)^2)+log(10^2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6.1588830833596715);
}

TEST(scp_correct, 36) {
  scp::Model model;
  model.ParseExpression("sqrt((16+9)*2^3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 14.142135623730951);
}

TEST(scp_correct, 37) {
  scp::Model model;
  model.ParseExpression("asin(0.5)^2+atan(1)^2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.8910059528761227);
}

TEST(scp_correct, 38) {
  scp::Model model;
  model.ParseExpression("(2+sin(0.5235987755982988))*2");
  EXPECT_DOUBLE_EQ(model.Calculate(), 5.0);
}

TEST(scp_correct, 39) {
  scp::Model model;
  model.ParseExpression("sqrt(16+9*2)*3");
  EXPECT_DOUBLE_EQ(model.Calculate(), 17.492855684535904);
}

TEST(scp_correct, 40) {
  scp::Model model;
  model.ParseExpression("(2+3)*5+x-4mod2");
  EXPECT_DOUBLE_EQ(model.Calculate(2896), 2921);
}

TEST(scp_correct, 41) {
  scp::Model model;
  model.ParseExpression("sqrt(16)+cos(x)+sin(3.14159/2)+tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(9339), 5.42235654692368);
}

TEST(scp_correct, 42) {
  scp::Model model;
  model.ParseExpression("acos(1)+asin(1)+atan(1)+ln(1)+log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.356194490192345);
}

TEST(scp_correct, 43) {
  scp::Model model;
  model.ParseExpression("2^3*5+15-x+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(8395), -8336.0);
}

TEST(scp_correct, 44) {
  scp::Model model;
  model.ParseExpression("cos(0)+sin(3.14159/2)-tan(3.14159/X)+acos(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(9977), 1.9996851167572804);
}

TEST(scp_correct, 45) {
  scp::Model model;
  model.ParseExpression("asin(0)*atan(1)/5mod4+log(x)");
  EXPECT_DOUBLE_EQ(model.Calculate(6371), 3.8042076050820413);
}

TEST(scp_correct, 46) {
  scp::Model model;
  model.ParseExpression("sqrt(x)+cos(0)-sin(3.14159/2)*tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(7522), 86.729465754981);
}

TEST(scp_correct, 47) {
  scp::Model model;
  model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)+x");
  EXPECT_DOUBLE_EQ(model.Calculate(3443), 3443.0);
}

TEST(scp_correct, 48) {
  scp::Model model;
  model.ParseExpression("log(10)*2^3*5+x-X");
  EXPECT_DOUBLE_EQ(model.Calculate(2065), 40.0);
}

TEST(scp_correct, 49) {
  scp::Model model;
  model.ParseExpression("sqrt(16)modx+cos(0)+sin(3.14159/2)");
  EXPECT_DOUBLE_EQ(model.Calculate(4641), 5.99999999999912);
}

TEST(scp_correct, 50) {
  scp::Model model;
  model.ParseExpression("tan(3.14159/4)+acos(1)-asin(0)*x");
  EXPECT_DOUBLE_EQ(model.Calculate(4033), 0.9999986732059836);
}

TEST(scp_correct, 51) {
  scp::Model model;
  model.ParseExpression("atan(1)+ln(1)*log(10)/x");
  EXPECT_DOUBLE_EQ(model.Calculate(1924), 0.7853981633974483);
}

TEST(scp_correct, 52) {
  scp::Model model;
  model.ParseExpression("x^3*5+15-x+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(1810), 29648703209.0);
}

TEST(scp_correct, 53) {
  scp::Model model;
  model.ParseExpression("cos(X)-1modx+sin(3.14159/2)*tan(3.14159/4)");
  EXPECT_DOUBLE_EQ(model.Calculate(3398), 0.359324287215802);
}

TEST(scp_correct, 54) {
  scp::Model model;
  model.ParseExpression("acos(1)+asin(0)^atan(1)+ln(1)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.0);
}

TEST(scp_correct, 55) {
  scp::Model model;
  model.ParseExpression("log(10)*2^3*5+x-4");
  EXPECT_DOUBLE_EQ(model.Calculate(162), 198.0);
}

TEST(scp_correct, 56) {
  scp::Model model;
  model.ParseExpression("sqrt(16)-cos(0)+sin(3.14159/2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.99999999999912);
}

TEST(scp_correct, 57) {
  scp::Model model;
  model.ParseExpression("tan(3.14159/4)+acos(1)*asin(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.9999986732059836);
}

TEST(scp_correct, 58) {
  scp::Model model;
  model.ParseExpression("atan(1)+ln(1)/log(10)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7853981633974483);
}

TEST(scp_correct, 59) {
  scp::Model model;
  model.ParseExpression("2^3*5+x-4+sqrt(16)");
  EXPECT_DOUBLE_EQ(model.Calculate(4299), 4339.0);
}

TEST(scp_correct, 60) {
  scp::Model model;
  model.ParseExpression("( 2 + 3 ) * 5 + x - 4  mod  2");
  EXPECT_DOUBLE_EQ(model.Calculate(2896), 2921);
}

TEST(scp_correct, 61) {
  scp::Model model;
  model.ParseExpression(" X ^ 3 * 5+15-x+sqrt(16) ");
  EXPECT_DOUBLE_EQ(model.Calculate(1810), 29648703209.0);
}

TEST(scp_correct, 62) {
  scp::Model model;
  model.ParseExpression("2 ^ 2 ^ 3 ");
  EXPECT_DOUBLE_EQ(model.Calculate(), 256);
}

TEST(scp_correct, 63) {
  scp::Model model;
  model.ParseExpression("(5+2.3e4)/(3.5-1.2e2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -197.46781115879827);
}

TEST(scp_correct, 64) {
  scp::Model model;
  model.ParseExpression("(4.5e3+2)*(6.7e2-3.2e-4)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3016338.55936);
}

TEST(scp_correct, 65) {
  scp::Model model;
  model.ParseExpression("(2.1e5^3)/(x-2.3e2)");
  EXPECT_DOUBLE_EQ(model.Calculate(6550), 1465348101265.8228);
}

TEST(scp_correct, 66) {
  scp::Model model;
  model.ParseExpression("(7.6e3mod5)+(3.4e4mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.0);
}

TEST(scp_correct, 67) {
  scp::Model model;
  model.ParseExpression("sin(0.5235987755982988)+cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.2071067811865475);
}

TEST(scp_correct, 68) {
  scp::Model model;
  model.ParseExpression("tan(1.0471975511965976)-sin(1.5707963267948966)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.7320508075688767);
}

TEST(scp_correct, 69) {
  scp::Model model;
  model.ParseExpression("asin(1)+acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 3.141592653589793);
}

TEST(scp_correct, 70) {
  scp::Model model;
  model.ParseExpression("atan(1)-asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.26179938779914935);
}

TEST(scp_correct, 71) {
  scp::Model model;
  model.ParseExpression("ln(2.3e+4)+log(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 13.924063087192078);
}

TEST(scp_correct, 72) {
  scp::Model model;
  model.ParseExpression("(sin(0.7853981633974483)+3.4e2)*(log(100)^3)/(xmod3)");
  EXPECT_DOUBLE_EQ(model.Calculate(5710), 2725.6568542494924);
}

TEST(scp_correct, 73) {
  scp::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(5))");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1428.0231519359106);
}

TEST(scp_correct, 74) {
  scp::Model model;
  model.ParseExpression(
      "(tan(1.0471975511965976)+1.2e-2)*(2.3e4^2)/(5mod3)+4.8e+4");
  EXPECT_DOUBLE_EQ(model.Calculate(), 461349438.60196793);
}

TEST(scp_correct, 75) {
  scp::Model model;
  model.ParseExpression("asin(0.5)+(4.5e-3*ln(2))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 0.5267179379108187);
}

TEST(scp_correct, 76) {
  scp::Model model;
  model.ParseExpression("(atan(1)+3.4e4)*(2.3e2^3)/(7mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 413687555939.45404);
}

TEST(scp_correct, 77) {
  scp::Model model;
  model.ParseExpression("ln(7.6e3)+log(100)*cos(0.7853981633974483)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 10.350117088647519);
}

TEST(scp_correct, 78) {
  scp::Model model;
  model.ParseExpression(
      "(sin(0.5235987755982988)+2.1e5)*(3.4e4^2)/(50e-1mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 242760578000000.0);
}

TEST(scp_correct, 79) {
  scp::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(4.5e3))");
  EXPECT_DOUBLE_EQ(model.Calculate(), -272.377166514941);
}

TEST(scp_correct, 80) {
  scp::Model model;
  model.ParseExpression("(tan(0.7853981633974483)+1.2e2)*(7.6e3^2)/(3mod2)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6988960000.0);
}

TEST(scp_correct, 81) {
  scp::Model model;
  model.ParseExpression("asin(0.5)+(2.1e5*ln(2))");
  EXPECT_DOUBLE_EQ(model.Calculate(), 145561.4315163641);
}

TEST(scp_correct, 82) {
  scp::Model model;
  model.ParseExpression("(atan(1)+6.7e-2)*(3.4e+4^3)/(7mod3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 33502657414173.305);
}

TEST(scp_correct, 83) {
  scp::Model model;
  model.ParseExpression("(x+2.3e4)/(X-1.2e2)+1.1e-1^(2*1.0471975511965976)");
  EXPECT_DOUBLE_EQ(model.Calculate(8106), 3.9048905738199187);
}

TEST(scp_correct, 84) {
  scp::Model model;
  model.ParseExpression(
      "(4.5e3+2)*(6.7e2-3.2e4)+sin(20.943951023931955)+cos(41.88790204786391)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -141047659.63397458);
}

TEST(scp_correct, 85) {
  scp::Model model;
  model.ParseExpression("(2.1e5^3)/(x-2.3e2)+tan(62.831853071795855)");
  EXPECT_DOUBLE_EQ(model.Calculate(1580), 6860000000000.0);
}

TEST(scp_correct, 86) {
  scp::Model model;
  model.ParseExpression("(7.6e3mod5)+(3.4e4mod2)-asin(1)-acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -3.141592653589793);
}

TEST(scp_correct, 87) {
  scp::Model model;
  model.ParseExpression(
      "sin(0.5235987755982988)+cos(0.7853981633974483)-atan(1)+acos(0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 1.9925049445839957);
}

TEST(scp_correct, 88) {
  scp::Model model;
  model.ParseExpression(
      "tan(1.0471975511965976)-sin(1.5707963267948966)+ln(2.3e4)-log(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 6.894486710199372);
}

TEST(scp_correct, 89) {
  scp::Model model;
  model.ParseExpression(
      "(sin(0.7853981633974483)+3.4e2)*(log(100)^3)/"
      "(7mod3)+8.4e2^(1.5707963267948966)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 41940.20011530107);
}

TEST(scp_correct, 90) {
  scp::Model model;
  model.ParseExpression("acos(0.5)-(2.3e3/ln(5))+tan(62.831853071795855)");
  EXPECT_DOUBLE_EQ(model.Calculate(), -1428.0231519359106);
}

TEST(scp_correct, 91) {
  scp::Model model;
  model.ParseExpression(
      "(tan(1.0471975511965976)+1.2e2)*(2.3e4^2)/(5mod3)+asin(0.5)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 32198127439.12557);
}

TEST(scp_correct, 92) {
  scp::Model model;
  model.ParseExpression("(atan(1)+3.4e4)*(2.3e2^3)/(7mod2)+ln(7.6e3)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 413687555948.38995);
}

TEST(scp_correct, 93) {
  scp::Model model;
  model.ParseExpression("(1.2e1 * 2) + (2.1e2 / 8.1e0)");
  EXPECT_DOUBLE_EQ(model.Calculate(), 49.925925925925924);
}

TEST(scp_correct, 94) {
  scp::Model model;
  model.ParseExpression("1/x");
  EXPECT_THROW(model.Calculate(), std::domain_error);
  EXPECT_DOUBLE_EQ(model.Calculate(2), 0.5);
}
