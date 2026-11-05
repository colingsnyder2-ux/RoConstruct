// from server: 30% by atomic.potato
struct S {
    float m0;
    float m4;
    float m8;
    float mc;
    float m10;
    float m14;
    float m18;
    float m1c;
    float m20;
    float m24;
    float m28;
    float m2c;
    float m30;
    float m34;
    float m38;
    float m3c;
};

struct T {
    float m0;
    float m4;
    float m8;
    float mc;
};

struct R {
    float m0;
    float m4;
    float m8;
    float mc;
};

R __stdcall func(S* a, T* b, S* c) {
    R r;
    r.m0 = c->m30 * b->mc + c->m10 * b->m4 + c->m20 * b->m8 + b->m0 * c->m0;
    r.m4 = c->m34 * b->mc + c->m14 * b->m4 + c->m4 * b->m0 + c->m24 * b->m8;
    r.m8 = c->m38 * b->mc + c->m18 * b->m4 + c->m8 * b->m0 + c->m28 * b->m8;
    r.mc = c->m3c * b->mc + c->m1c * b->m4 + c->mc * b->m0 + c->m2c * b->m8;
    return r;
}
