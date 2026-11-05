// from server: 51% by atomic.potato
struct X_007b6630 {
    char pad_0[0x10];
    void* f_10;
    char pad_14[0x4];
    void* f_18;
    void invoke(void* a, void* b);
};

void X_007b6630::invoke(void* a, void* b) {
    char* p = (char*)a;
    char* q;
    if (p != 0) {
        q = p - 0x1c;
    } else {
        q = 0;
    }
    float* src = (float*)b;
    float tmp[3];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    void* fn = f_10;
    char* arg = (char*)f_18 + (int)q;
    ((void (__thiscall*)(void*, void*))fn)(arg, tmp);
}
