// methods
public static double add (double v1, double v2);
public static double sub (double v1, double v2);
public static double mul (double v1, double v2);
public static double div (double v1, double v2);
public static double div (double v1, double v2, int scale);
public static double round (double v1, double v2);

//example
double v1 = 14, v2 = 9;
BigDecimal b1 = new BigDecimal(Double.toString(v1));
BigDecimal b2 = new BigDecimal(Double.toString(v2));
BigDecimal res = b1.divide(b2, 10, BigDecimal.ROUND_HALF_UP);

/*
ROUND PROPERTIES:

ROUND_CEILING: If the BigDecimal is positive, behave as for ROUND_UP; if negative, behave as for ROUND_DOWN.
ROUND_DOWN: Never increment the digit prior to a discarded fraction (i.e., truncate).
ROUND_FLOOR: If the BigDecimal is positive, behave as for ROUND_DOWN; if negative behave as for ROUND_UP.
ROUND_HALF_DOWN: Behave as for ROUND_UP if the discarded fraction is > .5; otherwise, behave as for ROUND_DOWN.
ROUND_HALF_EVEN: Behave as for ROUND_HALF_UP if the digit to the left of the discarded fraction is odd; behave as for ROUND_HALF_DOWN if it's even.
ROUND_HALF_UP: Behave as for ROUND_UP if the discarded fraction is >= .5; otherwise, behave as for ROUND_DOWN.
ROUND_UNNECESSARY: This "pseudo-rounding-mode" is actually an assertion that the requested operation has an exact result, hence no rounding is necessary.
ROUND_UP: Always increment the digit prior to a non-zero discarded fraction.
*/