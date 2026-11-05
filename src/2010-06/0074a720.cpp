// from server: 69% by atomic.potato
struct S {
    char pad0[0x18];
    int field18;
    char pad1[0x4];
    int field20;
    char pad2[0x1c];
    char field40;
    int method0();
    int method38();
};

extern "C" int __stdcall sub_5ee8e0(int, int);
extern "C" int __stdcall sub_717dd0(int);

int S::method0() {
    if (field40 != 0) {
        sub_717dd0(field20);
        field20 = 0;
        int* v = (int*)this;
        int (*fn)(S*) = (int (*)(S*))v[0];
        field40 = 0;
        int r = fn(this);
        int* p = (int*)r;
        if (p[6] >= 0x10)
            p = (int*)p[1];
        else
            p = (int*)((char*)p + 4);
        sub_5ee8e0((int)p, field18);
    }
    int* v2 = (int*)this;
    int (*fn2)(S*) = (int (*)(S*))v2[0x38 / 4];
    fn2(this);
    return 0;
}
