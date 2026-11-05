// from server: 38% by atomic.potato
extern "C" int __cdecl sym(unsigned char, void *);

struct S {
    unsigned char value[0x90];
    int f();
};

int S::f() {
    return sym(value[0], value + 0x94);
}
