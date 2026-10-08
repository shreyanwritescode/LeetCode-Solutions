char* intToRoman(int num) {
    static char *roman[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };
    static int value[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };
    static char result[20];
    int k = 0;
    for (int i = 0; i < 13; i++) {
        while (num >= value[i]) {
            num -= value[i];
            for (int j = 0; roman[i][j] != '\0'; j++)
                result[k++] = roman[i][j];
        }
    }
    result[k] = '\0';
    return result;
}