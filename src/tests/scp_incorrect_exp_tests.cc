#include "scp_calc_tests.h"

TEST(scp_mismatched_brackets, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(2+3*((5-2)+(3+4)*(2-1)"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(2+3)((5-2)+(3+4)(2-1)))"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(23^2+45^2-sqrt(9)"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(ln((e^3))^2)+log(10^2)"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt((16+9)*2^3))"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(asin(0.5)^2+atan(1)^2-"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("((2+sin(30))*2"), std::invalid_argument);
}

TEST(scp_mismatched_brackets, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(sqrt(16+92)*3))"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(((2+3)((5-2)+(3+4)(2-1))"),
               std::invalid_argument);
}

TEST(scp_mismatched_brackets, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin(30)+cos(60--tan(45)"),
               std::invalid_argument);
}
TEST(scp_incorrect_unary, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("-3*-5+15-4"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("--4/2"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("-+10^2"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("--+3"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("+-3"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("5%-2"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2*-"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("--3/42"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("-3*/5"), std::invalid_argument);
}

TEST(scp_incorrect_unary, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("6+-"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("7/-"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(+-+-8)"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("-9*-"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("++10/3"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("5*-(--3)"), std::invalid_argument);
}

TEST(scp_incorrect_unary_, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("-4/-"), std::invalid_argument);
}
TEST(scp_several_operators, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2++2"), std::invalid_argument);
}

TEST(scp_several_operators, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("3**5+15-4"), std::invalid_argument);
}

TEST(scp_several_operators, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("4//2"), std::invalid_argument);
}

TEST(scp_several_operators, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("10^^2"), std::invalid_argument);
}

TEST(scp_several_operators, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("5%%2"), std::invalid_argument);
}

TEST(scp_several_operators, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin(30)+cos(60)++tan(45)"),
               std::invalid_argument);
}

TEST(scp_several_operators, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("acos(0.5)++asin(0.5)+atan(1)"),
               std::invalid_argument);
}

TEST(scp_several_operators, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(2+3)((5-2))+(3+4)(2-1)"),
               std::invalid_argument);
}

TEST(scp_several_operators, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt(16+9*2)*3)/4"),
               std::invalid_argument);
}

TEST(scp_several_operators, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("ln(2)+log(10)++log(2)"),
               std::invalid_argument);
}
TEST(scp_functions_without_parentheses, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos30+sin45*tan60"),
               std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt16+sqrt9*2"), std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("ln2+log10-acos0.5"),
               std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin30*cos60+tan45"),
               std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("acos0.5+asin0.5+atan1"),
               std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt16+9*2-3"), std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("ln(e^5)+log102"), std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("acos0.5+asin0.5"), std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos45*sin30+tan60"),
               std::invalid_argument);
}

TEST(scp_functions_without_parentheses, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt16+sqrt(9*2)"),
               std::invalid_argument);
}
TEST(scp_expression_ends_on_operator, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+sin"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+cos"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+tan"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+asin"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+acos"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+atan"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+sqrt"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+ln"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+log"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)/"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 10) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)*"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 11) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)^"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 12) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)+"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 13) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)-"),
               std::invalid_argument);
}

TEST(scp_expression_ends_on_operator, 14) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30)+sin(45)*tan(60)mod"),
               std::invalid_argument);
}

TEST(scp_two_decimal_points, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2+2.25+3.25.48-3"),
               std::invalid_argument);
}

TEST(scp_two_decimal_points, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("1..5 + 2"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("3.4.5 - 1"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("6..7 * 4"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2 / 3..1"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin(30.2.3)"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(4..56)"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("tan(5..89)"), std::invalid_argument);
}

TEST(scp_two_decimal_points, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("54..23 + sqrt(16)"),
               std::invalid_argument);
}

TEST(scp_two_decimal_points, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("log(10..10)"), std::invalid_argument);
}

TEST(scp_two_decimal_points_, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("ln(23..34)"), std::invalid_argument);
}
TEST(scp_loose_decimal_points, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30).sin(5)"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("cos(30).5+2"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression(".sin(5)-8"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("5+7-2^.*2"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression(". + 5"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("6 * ."), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sqrt(.)"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression(". / 3"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 8) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin(.)"), std::invalid_argument);
}

TEST(scp_loose_decimal_points, 9) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("log(.)"), std::invalid_argument);
}

TEST(scp_loose_decimal_points_, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2 + . * 4"), std::invalid_argument);
}

TEST(scp_loose_decimal_points_, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("- 2 / ."), std::invalid_argument);
}

TEST(scp_loose_decimal_points_, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("tan(45)."), std::invalid_argument);
}

TEST(scp_loose_decimal_points_, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression(".sin(45)"), std::invalid_argument);
}

TEST(scp_spaces, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("sin(4 5)"), std::invalid_argument);
}

TEST(scp_spaces, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("lo g(10)*2^3*5+x-x"),
               std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 0) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("5+2.3e.4"), std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 1) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("3.5-1.2e/2"), std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 2) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(4.5e + 2)*(6.7e2-3.2e-4)"),
               std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 3) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(2.1e5^3)/(x-e2)"),
               std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 4) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("(7.6e3mod5)+(e mod2)"),
               std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 5) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("ln(2.3 e+4)+log(7.6e3)"),
               std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 6) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("acos(0.5)-e"), std::invalid_argument);
}

TEST(scp_incorrect_e_notation, 7) {
  scp::Model model;
  EXPECT_THROW(model.ParseExpression("2-2.1e2."), std::invalid_argument);
}
