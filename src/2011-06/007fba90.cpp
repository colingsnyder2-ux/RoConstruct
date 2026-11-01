// from server: 100% by tester
struct DummyJob {
    void func(double*, int);
};

void DummyJob::func(double* out, int) {
    *out = 0.0;
}
