// from server: 68% by king_originala
extern "C" void __stdcall cleanup(void*);

struct S {
    typedef void (__thiscall *Method)(S*);
    Method* table;
    void f(void*);
};

void S::f(void* p)
{
    cleanup(p);
    table[24](this);
}
