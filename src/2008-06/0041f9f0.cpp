// from server: 100% by king_originala
struct S;

struct VTable {
    void *slots[88];
    void (__thiscall *invoke)(S *);
};

struct S {
    VTable *vtable;
    void f(int unused, int *result);
};

void S::f(int unused, int *result)
{
    vtable->invoke(this);
    *result = 0;
}
