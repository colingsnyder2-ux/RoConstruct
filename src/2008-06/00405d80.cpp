// from server: 100% by king_originala
struct S;

struct Registry {
    void remove(S* const* object);
};

struct S {
    unsigned long vtable;
    void f();
};

void S::f()
{
    vtable = 0x80b2e0;
    S* object = this;
    reinterpret_cast<Registry*>(0x96c23c)->remove(&object);
}
