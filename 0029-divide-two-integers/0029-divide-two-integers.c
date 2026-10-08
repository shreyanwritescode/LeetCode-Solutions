int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1) {
        return 2147483647;
    }
    long long a = dividend;
    long long b = divisor;
    int negative = 0;
    if (a < 0) {
        a = -a;
        negative = !negative;
    }
    if (b < 0) {
        b = -b;
        negative = !negative;
    }
    long long result = 0;
    while (a >= b) {
        long long temp = b;
        long long multiple = 1;
        while (a >= (temp << 1)) {
            temp = temp << 1;
            multiple = multiple << 1;
        }
        a = a - temp;
        result = result + multiple;
    }
    if (negative) {
        result = -result;
    }
    return (int)result;
}