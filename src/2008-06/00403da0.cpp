// from server: 100% by king_originala
struct A {
    unsigned long value;
};

struct B {
    unsigned long value;
};

extern "C" long __stdcall query(B *, const void *, void **);

struct S : A, B {
    long f(const void *, void **);
};

long S::f(const void *id, void **result)
{
    return query(static_cast<B *>(this), id, result);
}
