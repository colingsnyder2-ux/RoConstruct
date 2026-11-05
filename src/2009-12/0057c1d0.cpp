// from server: 100% by atomic.potato
struct V {
    int f(int);
};

extern "C" void __stdcall sub_485670(int, int);

int V::f(int a) {
    int* src = (int*)a;
    sub_485670(*(int*)(src + 1), 1);
    int i = 0;
    if (*(int*)((char*)this + 4) > 0) {
        int off = 0;
        do {
            float* s = (float*)(*(int*)src + off);
            float* d = (float*)(*(int*)this + off);
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
            i++;
            off += 16;
        } while (i < *(int*)((char*)this + 4));
    }
    return (int)this;
}
