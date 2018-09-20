import decimal as D
D.getcontext().prec = 10
D.getcontext().rounding = D.ROUND_HALF_DOWN
print(D.Decimal(14) / D.Decimal("9"))