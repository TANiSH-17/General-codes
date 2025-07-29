string toBinary(int num) {
    string res = "";
    while(num > 0) {
        res = char('0' + (num % 2)) + res;
        num /= 2;
    }
    return res;
}
