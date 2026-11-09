// from server: 70% by atomic.potato
typedef unsigned long DWORD;

extern DWORD g_00CCA794;

extern void *__cdecl Function_005BAA40();
extern void *__cdecl Function_0080A05E(int);

struct Inner {
    void **vtable;
    void *field4;
};

struct S {
    void *field0;
    Inner *field4;
    S *ctor(void *arg);
};

S *S::ctor(void *arg)
{
    g_00CCA794++;
    field0 = Function_005BAA40();
    Inner *p = (Inner *)Function_0080A05E(8);
    if (p != 0) {
        p->vtable = (void **)0x00A7B304;
        p->field4 = *(void **)arg;
    } else {
        p = 0;
    }
    Inner *old = field4;
    if (&arg != (void **)&field4) {
        field4 = p;
    } else {
        p = old;
    }
    if (p != 0) {
        void **vt = p->vtable;
        void (*fn)(Inner *, int) = (void (*)(Inner *, int))vt[0];
        fn(p, 1);
    }
    return this;
}
