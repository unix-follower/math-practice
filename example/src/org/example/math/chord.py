import logging
import textwrap

from org.example.math.config.logging_config import logger


def slope_angle(x1, x2):
    """
         BC   BD - CD   f(x₂) - f(x₁)
    AB = -- = ------- = -------------
         AC     ED        (x₂ - x₁)
    :return: (f(x₂) - f(x₁)) / (x₂ - x₁)
    """
    def f(x):
        return pow(x, 2)

    x2_square = f(x2)
    x1_square = f(x1)
    denominator_subtraction_result = x2 - x1
    result = (x2_square - x1_square) / denominator_subtraction_result

    if logger.isEnabledFor(logging.INFO):
        numerator = "f({x2}) - f({x1})".format(x2=x2, x1=x1)
        numerator_length = len(numerator)

        minus_position = numerator_length // 2
        denominator_x2 = "{0}".format(x2)
        leading_whitespaces = " " * (minus_position - len(denominator_x2) - 1)
        denominator_str = leading_whitespaces + denominator_x2 + " - " + "{0}".format(x1)

        line1 = "-" * numerator_length

        numerator_squares_str = "{x2_square} - {x1_square}".format(x2_square=x2_square, x1_square=x1_square)
        numerator_squares_str_length = len(numerator_squares_str)
        denominator_subtraction_result_str = str(denominator_subtraction_result)
        denominator_subtraction_result_str_length = len(denominator_subtraction_result_str)
        if numerator_squares_str_length > denominator_subtraction_result_str_length:
            line2 = "-" * numerator_squares_str_length
        else:
            line2 = "-" * denominator_subtraction_result_str_length
        denominator_subtraction_position = (numerator_length + numerator_squares_str_length) - (
            numerator_squares_str_length // 2)
        denominator_str_length = len(denominator_str)
        denominator_subtraction_leading_whitespaces = " " * (
            denominator_subtraction_position - denominator_str_length - 1)

        denominator_subtraction_str = denominator_subtraction_leading_whitespaces + denominator_subtraction_result_str
        if (len(line2) - len(denominator_subtraction_str)) < 0:
            if denominator_subtraction_result_str_length <= 2:
                denominator_subtraction_leading_whitespaces = " " * (numerator_length - denominator_str_length + 2)
            elif denominator_subtraction_result_str_length == 3:
                denominator_subtraction_leading_whitespaces = " " * (numerator_length - denominator_str_length + 3)
            else:
                denominator_subtraction_leading_whitespaces = " " * (numerator_length - denominator_str_length)

            denominator_subtraction_str = \
                denominator_subtraction_leading_whitespaces + denominator_subtraction_result_str

        msg = textwrap.dedent(
            """
            {numerator}   {numerator_squares}
            {line1} = {line2} = {result}
            {denominator}   {denominator_subtraction}
            """.format(
                numerator=numerator,
                line1=line1,
                denominator=denominator_str,
                numerator_squares=numerator_squares_str,
                line2=line2,
                denominator_subtraction=denominator_subtraction_str,
                result=result
            )
        )
        logger.info(msg)

    return result
