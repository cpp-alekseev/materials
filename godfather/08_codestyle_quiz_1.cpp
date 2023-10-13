for (size_t i = 0; i < polynom.size(); ++i) {
    (i % 2 ? odd.emplace_back(polynom[i] : even.emplace_back(polynom[i])));
    (i % 2 ? odd : even).emplace_back(polynom[i]); // odd.emplace_back / event.emplace_back
}
