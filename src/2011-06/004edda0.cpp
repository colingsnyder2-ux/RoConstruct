// from server: 58% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    int field8;
    int fieldC;
    int field10;
    int f(int a, int b);
};

extern "C" void __cdecl sub_80a058(void*);

int S::f(int a, int b) {
    int* p = (int*)a;
    int* q = (int*)*p;
    *p = (int)q;
    field10--;
    int r;
    if (q != 0) {
        r = (int)((char*)q - 0x148);
    } else {
        r = 0;
    }
    sub_80a058((void*)r);
    int e = fieldC;
    if (b != e) {
        return 1;
    }
    if (field10 == 0) {
        fieldC = field4 + field8 * 4;
        return 1;
    }
    if (*((int*)e) != 0) {
        return 1;
    }
    do {
        fieldC += 4;
    } while (*((int*)fieldC) == 0);
    return 1;
}
