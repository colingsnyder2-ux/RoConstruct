// from server: 38% by atomic.potato
struct S {
    char pad0[0x20];
    char field20;
    int f(char arg);
};

extern "C" int __cdecl sub_4215F0(void*);

struct T {
    int g(char arg);
};

extern "C" int __cdecl sub_6EC130(S* self, char arg);

int S::f(char arg) {
    char* p = &field20;
    int b = sub_4215F0(p);
    sub_6EC130(this, arg);
    if (p) {
        *p = (char)b;
    }
    return 0;
}
