// from server: 35% by atomic.potato
struct Inner {
    char pad[8];
    void method(int, void*, void*);
};

struct Outer {
    Inner* p;
};

struct S {
    void __cdecl f(void*);
};

void S::f(void* a)
{
    Outer* o = (Outer*)a;
    Inner* in = o->p;
    void* local1;
    void* local2;
    char flag = 0;
    in->method(0, &local1, &local2);
}
