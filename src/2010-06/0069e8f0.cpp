// from server: 48% by atomic.potato
struct Inner {
    virtual int f(int);
};

struct Outer {
    char pad[0x20];
    Inner* inner;

    int f(int a);
};

struct Vec {
    char pad0[0xe0];
    int* begin;
    int* end;
};

extern "C" void __stdcall sub_401690(void*, void*);
extern "C" Vec* __cdecl sub_5b8f20();
extern "C" void __cdecl invalid_parameter_noinfo();

int Outer::f(int a) {
    int r = inner->f(a);
    sub_401690((void*)0x5b8f80, (void*)0xc182e4);
    Vec* v = sub_5b8f20();
    int n = (int)(v->end - v->begin) >> 2;
    if ((unsigned)r >= (unsigned)n) {
        return -1;
    }
    if ((unsigned)r >= (unsigned)((int)(v->end - v->begin) >> 2)) {
        invalid_parameter_noinfo();
    }
    return v->begin[r];
}
