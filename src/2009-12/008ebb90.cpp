// from server: 76% by atomic.potato
struct S;

extern "C" S* __stdcall sub_7f5f40(S*);

struct VTable
{
    void (__thiscall *f)(S*, S*, void*, int);
};

struct S
{
    int f(int);
};

int S::f(int value)
{
    S* object = sub_7f5f40(this);
    VTable* table = *(VTable**)object;
    table->f(object, this, (void*)value, 0);
    return 0;
}
