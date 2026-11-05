// from server: 37% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    char* field8;
    void* field10;
    char pad14[4];
    int field14;
    void SetValue(int, double*);
};

void S::SetValue(int a, double* b) {
    char* p = (char*)a;
    if (p != 0) {
        p -= 0x1c;
    }
    double* d = (double*)(field8 + (int)p);
    double v = *b;
    if (v != *d) {
        *d = v;
        if (field10 != 0) {
            ((void (__stdcall*)(int))field10)(field4);
            ((void (__stdcall*)(int, int))field10)(field4, field14 + (int)p);
        }
        ((void (__stdcall*)(int))0x40c080)(field4);
    }
}
