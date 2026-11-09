// from server: 86% by atomic.potato
struct S_func_006ee950 {
    char pad0[200];
    char m_x;
    void f();
};

struct Sub {
    char pad0[0x1c];
    int m1c;
    char pad1[0x4];
    int m24;
};

struct Inner {
    char pad0[0xf8];
    void f(int);
};

struct S {
    char pad0[0xcc];
    Sub* mcc;
    char pad1[0x4];
    Sub* md4;
    char pad2[0x4];
    Sub* mdc;
    char pad3[0x4];
    Sub* me4;
    char pad4[0x4];
    Sub* mec;
    char pad5[0x4];
    void g();
};

void S::g()
{
    ((S_func_006ee950*)((char*)this + 0))->f();

    Sub* a = mcc;
    char r1;
    if (a == 0) r1 = 1;
    else if (a->m24 == 0 && a->m1c == 0) r1 = 1;
    else r1 = 0;
    ((Inner*)((char*)this + 0xf8))->f(r1 == 0);

    Sub* b = md4;
    char r2;
    if (b == 0) r2 = 1;
    else if (b->m24 == 0 && b->m1c == 0) r2 = 1;
    else r2 = 0;
    ((Inner*)((char*)this + 0x120))->f(r2 == 0);

    Sub* c = mdc;
    char r3;
    if (c == 0) r3 = 1;
    else if (c->m24 == 0 && c->m1c == 0) r3 = 1;
    else r3 = 0;
    ((Inner*)((char*)this + 0x148))->f(r3 == 0);

    Sub* d = me4;
    char r4;
    if (d == 0) r4 = 1;
    else if (d->m24 == 0 && d->m1c == 0) r4 = 1;
    else r4 = 0;
    ((Inner*)((char*)this + 0x170))->f(r4 == 0);

    Sub* e = mec;
    char r5;
    if (e == 0) r5 = 1;
    else if (e->m24 == 0 && e->m1c == 0) r5 = 1;
    else r5 = 0;
    ((Inner*)((char*)this + 0x198))->f(r5 == 0);
}
