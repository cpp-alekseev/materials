for (size_t i = 0; i + 1 < last || negative; ++i) {
    if (block[i] >= MAX_BLOCK_VALUE) {
        block[i + 1] += block[i] / MAX_BLOCK_VALUE;
        block[i] %= MAX_BLOCK_VALUE;
    }
    if (block[i] < 0) {
        coefficient = (-block[i] + MAX_BLOCK_VALUE - 1) / MAX_BLOCK_VALUE;
        block[i + 1] -= coefficient;
        block[i] += coefficient * MAX_BLOCK_VALUE;
    }

    negative = block[i + 1] < 0
}
