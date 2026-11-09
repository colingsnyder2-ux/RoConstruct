// from server: 79% by atomic.potato
struct S {
    int (__stdcall *vtbl)(void *);
    float f(void *p);
};

float S::f(void *p) {
    if (p != 0) {
        char *q = (char *)p - 0x1c;
        if (q != 0) {
            int r = this->vtbl(q + 0x94);
            return (float)r;
        }
    }
    int r = this->vtbl(0);
    return (float)r;
}
