// from server: 48% by Intel
struct GenericJob {
    int getTime(double* out);
};

int GenericJob::getTime(double* out) {
    double value;
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x23C) == 0) {
        value = *reinterpret_cast<double*>(0xB53EF8);
    } else {
        value = 0.0;
    }
    *out = value;
    return 0;
}
