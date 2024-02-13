import math

alph = '0123456789ABCDEF'

def to_dec(num: str, radix: int) -> int:

    tmp = 1
    res = 0

    for digit in num[::-1]:
        res += alph.index(digit) * tmp
        tmp *= radix

    return res


def dec_to_other(num: float, radix: int) -> str:
    num = float(num)
    str_num = str(num)
    fractional_part, whole_part = math.modf(num)
    res = 0
    ans = ''

    whole_part = int(whole_part)

    while whole_part >= radix:
        ans += alph[whole_part % radix]
        whole_part //= radix

    ans += alph[whole_part]

    ans = ans[::-1]

    if num.is_integer():
        return ans

    ans += '.'

    for i in range(10):
        fractional_part *= radix
        tmp = math.modf(fractional_part)
        ans += alph[int(tmp[1])]
        fractional_part = tmp[0]

    return ans
