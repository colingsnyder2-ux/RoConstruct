// from server: 58% by atomic.potato
struct S {
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    void f(int, float*);
};

void S::f(int a, float* b) {
    S* p;
    if (a != 0) {
        p = (S*)((char*)a - 0x1c);
    } else {
        p = 0;
    }
    int esi = m20;
    int ecx = *(int*)((char*)p + 0x94);
    ecx = *(int*)(ecx + esi);
    ecx += m1c;
    void (*fn)(void*, float) = (void (*)(void*, float))m18;
    float val = *b;
    fn((void*)((char*)p + ecx + 0x94), val);
}
