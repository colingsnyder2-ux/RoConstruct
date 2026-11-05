// from server: 64% by colin
extern "C" void* __stdcall memmove_s(void*, unsigned int, const void*, unsigned int);

struct S {
    char pad0[0x10];
    unsigned int* p10;
    char pad14[0xC];
    unsigned int* p20;
    char pad24[0xC];
    unsigned int* p30;
    char pad34[0x8];
    unsigned char b3c;
    char pad3d[0x3];
    char buf40[0x10];
    unsigned int n50;
    unsigned int n54;
    int n58;
    int f();
};

int S::f() {
    if (*p20 == 0) {
        unsigned int* vt = *(unsigned int**)this;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[0x54 / 4];
        fn(this);
    }
    unsigned int* base = p20;
    unsigned int cur = *base;
    unsigned int end = *p30 + cur;
    if (cur < end) {
        return *(unsigned char*)cur;
    }
    unsigned int off = cur - *p10;
    int* pn58 = &n58;
    int* sel = pn58;
    if (n58 < (int)off) {
        sel = (int*)&off;
    }
    int amount = *sel;
    if (amount != 0) {
        memmove_s((char*)this + 0x50 + (n58 - amount), amount, (void*)(cur - amount), amount);
    }
    unsigned int newcur = n58 + n50;
    *p10 = newcur - amount;
    *p20 = newcur;
    *p30 = 0;
    int r = ((int (__stdcall *)(char*, unsigned int, unsigned int))0x54fcb0)(buf40, n50 + n58, n54 - n58);
    if (r == -1) {
        b3c = 1;
        r = 0;
    }
    unsigned int c = *p20;
    *p30 = (n58 + n50 + r) - c;
    if (r != 0) {
        return *(unsigned char*)*p20;
    }
    return -1;
}
