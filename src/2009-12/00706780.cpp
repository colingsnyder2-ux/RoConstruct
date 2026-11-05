// from server: 45% by atomic.potato
struct Inner {
    char pad[8];
    void method(int, int, int, int);
};

struct Outer {
    Inner* p;
};

struct S {
    void __cdecl f(Outer*);
};

void S::f(Outer* o) {
    Inner* p = o->p;
    int local = 0;
    char flag = 0;
    p->method(0, (int)&local, (int)&flag, (int)&flag);
}
