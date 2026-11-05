// from server: 51% by atomic.potato
struct Inner {
    char pad[0x20];
    int f();
};

struct Arg {
    char pad[0x10];
    int g(int*);
};

struct S {
    char pad[0x1c];
    Inner* p;
    int method(Arg* a, int b, int c);
};

extern "C" int __stdcall sub_6b11b0(int);

int S::method(Arg* a, int b, int c)
{
    if (a->g(&b))
        return 0;
    int v;
    if (*(int*)((char*)a + 0x10) == 0)
        return 0;
    v = sub_6b11b0(b);
    Inner* p = this->p;
    return (*(int(**)(Inner*, int, int))((*(int*)p) + 0x10))(p, v, b);
}
