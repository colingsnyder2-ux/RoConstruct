// from server: 59% by atomic.potato
struct Inner {
    int a;
    int b;
};

struct Outer {
    char pad[0x70];
    Inner inner;
};

struct S {
    char pad0[4];
    Outer* p;
    void f(int* out, int arg);
};

extern "C" void* __stdcall sub_534e00(void* p, int* out, int arg);

void S::f(int* out, int arg)
{
    Inner tmp;
    void* r = sub_534e00(&p->inner, (int*)&tmp, arg);
    Inner* q = (Inner*)r;
    out[0] = (int)this;
    out[1] = q->a;
    out[2] = q->b;
}
