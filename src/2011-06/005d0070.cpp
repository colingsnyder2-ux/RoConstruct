// from server: 83% by atomic.potato
struct Inner {
    int value;
};

struct S {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int f(int);
};

extern "C" Inner* __cdecl sub_5c86c0(int);

int S::f(int a) {
    Inner* p = sub_5c86c0(a);
    int idx = p->value;
    if (idx < 0) return 0;
    int count = (int)((end - begin));
    if ((unsigned)idx >= (unsigned)count) return 0;
    return begin[idx].value;
}
