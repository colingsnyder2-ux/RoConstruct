// from server: 100% by king_originala
extern void* factoryName;

struct S {
    typedef void (__thiscall *Method)(S*, void*);
    Method* vtable;
    void f();
};

void S::f()
{
    vtable[208](this, factoryName);
}
