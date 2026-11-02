// from server: 95% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Str {
    char b[0x1c];
    Str(const Str&);
    ~Str();
};

struct Vec {
    int v[4];
    Vec(const Vec&);
    ~Vec();
};

struct Counted {
    void* vt;
    long use;
};

struct Count {
    Counted* pi;
    Count(const Count& r) : pi(r.pi) {
        if (pi != 0) _InterlockedExchangeAdd((volatile long*)&pi->use, 1);
    }
};

struct S {
    float f;
    int i;
    Str s;
    Vec v;
    int a;
    void* p;
    Count c;
    S(const S& o);
};

S::S(const S& o) : f(o.f), i(o.i), s(o.s), v(o.v), a(o.a), p(o.p), c(o.c) {
}
