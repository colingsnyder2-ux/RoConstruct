// from server: 40% by atomic.potato
struct S
{
    int f(void*, void*);
};

typedef int (__thiscall *Fn)(void*, void*);

extern "C" void* __cdecl sub_60cbd0(void*, void*);

int S::f(void* a, void* b)
{
    void* p;
    void* q = sub_60cbd0(a, &p);
    void* v = *(void**)(*(int**)((char*)this + 0x1c));
    return ((Fn)v)((*(void**)((char*)this + 0x1c)), q);
}
