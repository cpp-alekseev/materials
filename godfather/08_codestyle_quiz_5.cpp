for (int i = static_cast<int>(sz); i > 0; i -= 9) {
    a = 0;
    for (int j = max(0, i - 9); j < i; ++j) {
        a = a * 10 + cur[j] - '0';
    }
    x.num.push_back(a);
}
