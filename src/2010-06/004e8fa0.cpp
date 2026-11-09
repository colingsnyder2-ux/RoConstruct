// from server: 78% by atomic.potato




extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl sub_4E6840(void* dst, void* src);

struct Inner {
    char pad[0x24];
};

struct Holder {
    int a;
    int b;
    int c;
    int d;
    Inner inner;
    char e;
    char f;
};

Holder* __cdecl sub_4E8FA0(int a, int b, int c, int* d, char e) {
    Holder* p = (Holder*)operator_new(0x38);
    if (p != 0) {
        p->a = a;
        p->b = b;
        p->c = c;
        p->d = *d;
        sub_4E6840(&p->inner, d + 1);
        p->e = e;
        p->f = 0;
    }
    return p;
}
