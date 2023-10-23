#include "s21_calc_tests.h"

TEST(s21_mismatched_brackets, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(2+3*((5-2)+(3+4)*(2-1)"));
}

TEST(s21_mismatched_brackets, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(2+3)((5-2)+(3+4)(2-1)))"));
}

TEST(s21_mismatched_brackets, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(23^2+45^2-sqrt(9)"));
}

TEST(s21_mismatched_brackets, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(ln((e^3))^2)+log(10^2)"));
}

TEST(s21_mismatched_brackets, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt((16+9)*2^3))"));
}

TEST(s21_mismatched_brackets, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(asin(0.5)^2+atan(1)^2-"));
}

TEST(s21_mismatched_brackets, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("((2+sin(30))*2"));
}

TEST(s21_mismatched_brackets, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(sqrt(16+92)*3))"));
}

TEST(s21_mismatched_brackets, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(((2+3)((5-2)+(3+4)(2-1))"));
}

TEST(s21_mismatched_brackets, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sin(30)+cos(60--tan(45)"));
}
TEST(s21_incorrect_unary, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("-3*-5+15-4"));
}

TEST(s21_incorrect_unary, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("--4/2"));
}

TEST(s21_incorrect_unary, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("-+10^2"));
}

TEST(s21_incorrect_unary, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("--+3"));
}

TEST(s21_incorrect_unary, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("+-3"));
}

TEST(s21_incorrect_unary, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("5%-2"));
}

TEST(s21_incorrect_unary, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("2*-"));
}

TEST(s21_incorrect_unary, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("--3/42"));
}

TEST(s21_incorrect_unary, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("-3*/5"));
}

TEST(s21_incorrect_unary, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("6+-"));
}

TEST(s21_incorrect_unary_, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("7/-"));
}

TEST(s21_incorrect_unary_, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(+-+-8)"));
}

TEST(s21_incorrect_unary_, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("-9*-"));
}

TEST(s21_incorrect_unary_, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("++10/3"));
}

TEST(s21_incorrect_unary_, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("5*-(--3)"));
}

TEST(s21_incorrect_unary_, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("-4/-"));
}
TEST(s21_several_operators, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("2++2"));
}

TEST(s21_several_operators, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("3**5+15-4"));
}

TEST(s21_several_operators, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("4//2"));
}

TEST(s21_several_operators, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("10^^2"));
}

TEST(s21_several_operators, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("5%%2"));
}

TEST(s21_several_operators, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sin(30)+cos(60)++tan(45)"));
}

TEST(s21_several_operators, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("acos(0.5)++asin(0.5)+atan(1)"));
}

TEST(s21_several_operators, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("(2+3)((5-2))+(3+4)(2-1)"));
}

TEST(s21_several_operators, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt(16+9*2)*3)/4"));
}

TEST(s21_several_operators, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("ln(2)+log(10)++log(2)"));
}
TEST(s21_functions_without_parentheses, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos30+sin45*tan60"));
}

TEST(s21_functions_without_parentheses, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt16+sqrt9*2"));
}

TEST(s21_functions_without_parentheses, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("ln2+log10-acos0.5"));
}

TEST(s21_functions_without_parentheses, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sin30*cos60+tan45"));
}

TEST(s21_functions_without_parentheses, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("acos0.5+asin0.5+atan1"));
}

TEST(s21_functions_without_parentheses, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt16+9*2-3"));
}

TEST(s21_functions_without_parentheses, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("ln(e^5)+log102"));
}

TEST(s21_functions_without_parentheses, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("acos0.5+asin0.5"));
}

TEST(s21_functions_without_parentheses, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos45*sin30+tan60"));
}

TEST(s21_functions_without_parentheses, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt16+sqrt(9*2)"));
}
TEST(s21_expression_ends_on_operator, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos(30)+sin(45)*tan(60)+cos"));
}
TEST(s21_two_decimal_points, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("2+2.25+3.25.48-3"));
}

TEST(s21_two_decimal_points, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("1..5 + 2"));
}

TEST(s21_two_decimal_points, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("3.4.5 - 1"));
}

TEST(s21_two_decimal_points, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("6..7 * 4"));
}

TEST(s21_two_decimal_points, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("2 / 3..1"));
}

TEST(s21_two_decimal_points, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sin(30.2.3)"));
}

TEST(s21_two_decimal_points, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos(4..56)"));
}

TEST(s21_two_decimal_points, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("tan(5..89)"));
}

TEST(s21_two_decimal_points, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("54..23 + sqrt(16)"));
}

TEST(s21_two_decimal_points, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("log(10..10)"));
}

TEST(s21_two_decimal_points_, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("ln(23..34)"));
}
TEST(s21_loose_decimal_points, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos(30).sin(5)"));
}

TEST(s21_loose_decimal_points, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("cos(30).5+2"));
}

TEST(s21_loose_decimal_points, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression(".5-8"));
}

TEST(s21_loose_decimal_points, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("5+7-2^2."));
}

TEST(s21_loose_decimal_points, 4) {
  Model model;
  EXPECT_FALSE(model.ParseExpression(". + 5"));
}

TEST(s21_loose_decimal_points, 5) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("6 * ."));
}

TEST(s21_loose_decimal_points, 6) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sqrt(.)"));
}

TEST(s21_loose_decimal_points, 7) {
  Model model;
  EXPECT_FALSE(model.ParseExpression(". / 3"));
}

TEST(s21_loose_decimal_points, 8) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("sin(.)"));
}

TEST(s21_loose_decimal_points, 9) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("log(.)"));
}

TEST(s21_loose_decimal_points_, 0) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("2 + . * 4"));
}

TEST(s21_loose_decimal_points_, 1) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("- 2 / ."));
}

TEST(s21_loose_decimal_points_, 2) {
  Model model;
  EXPECT_FALSE(model.ParseExpression("tan(45)."));
}

TEST(s21_loose_decimal_points_, 3) {
  Model model;
  EXPECT_FALSE(model.ParseExpression(".sin(45)"));
}