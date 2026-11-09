// from server: 83% by atomic.potato
struct Elem {
    int value;
};

struct Container {
    char pad_00[0x68];
    Elem* begin;
    Elem* end;
};

struct S {
    char pad_00[0x6c];
    int f(int);
};

extern "C" int* __cdecl sub_5c5730(int);

int S::f(int a) {
    int* p = sub_5c5730(a);
    int idx = *p;
    if (idx < 0)
        return 0;
    Container* c = (Container*)this;
    int count = (int)((c->end - c->begin));
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return c->begin[idx].value;
}
