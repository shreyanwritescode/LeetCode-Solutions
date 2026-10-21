#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool isNumber(char* s) {
    int i = 0, n = strlen(s);
    bool digit = false, dot = false, exp = false;
    while (i < n && s[i] == ' ')
        i++;
    while (n > i && s[n - 1] == ' ')
        n--;
    for (; i < n; i++) {
        if (isdigit(s[i]))
            digit = true;
        else if (s[i] == '.') {
            if (dot || exp)
                return false;
            dot = true;
        }
        else if (s[i] == 'e' || s[i] == 'E') {
            if (exp || !digit)
                return false;
            exp = true;
            digit = false;
        }
        else if (s[i] == '+' || s[i] == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
        }
        else
            return false;
    }
    return digit;
}