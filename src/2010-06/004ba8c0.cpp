// from server: 57% by atomic.potato
struct S
{
    void f(void* a, void* b);
};

typedef void (__thiscall *Callback)(void*, void*);

void S::f(void* a, void* b)
{
    Callback p = *(Callback*)*(void**)a;
    p(this, b);
}
