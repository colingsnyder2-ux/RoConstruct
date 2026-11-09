// from server: 100% by Intel
struct DummyJob {
    void func(double*, int);
};

void DummyJob::func(double* out, int) {
    *out = 0.0;
}
