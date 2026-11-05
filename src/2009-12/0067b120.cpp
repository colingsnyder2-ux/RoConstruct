// from server: 31% by atomic.potato
struct Inner {
    char pad0[0xc];
    void* begin;
    char pad1[4];
    void* end;
};

struct Mid {
    char pad0[0x50];
    Inner* inner;
};

struct Outer {
    char pad0[0xc];
    void* field;
};

extern "C" Mid* __stdcall sub_503120(void*);

struct S {
    char pad0[0xc];
    void* field;
    bool f();
};

bool S::f() {
    if (field == 0) {
        return false;
    }
    Mid* m = sub_503120(field);
    if (m == 0) {
        return false;
    }
    Inner* in = m->inner;
    if (in == 0) {
        return 0 < 0;
    }
    return 0 < (int)(((char*)in->end - (char*)in->begin) >> 3);
}
