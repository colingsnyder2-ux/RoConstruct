// from server: 44% by atomic.potato
struct PartInstance {
    int count;
    char pad0[8];
    float* data;
    float get();
};

float PartInstance::get() {
    float a = 0.0f;
    float b = 0.0f;
    float c = 0.0f;
    int n = count;
    int i = 0;
    if (n >= 2) {
        float* p = data;
        int k = ((unsigned)(n - 2) >> 1) + 1;
        i = k + k;
        do {
            a += p[0];
            b += p[1];
            p += 2;
        } while (--k);
    }
    if (i < n) {
        c = data[i];
    }
    return (a + b + c) / (float)n;
}
