// from server: 25% by atomic.potato
struct S_func_007b2f20 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

struct S {
    char pad0[8];
    void f(void* a1);
};

void S::f(void* a1)
{
    S_func_007b2f20* p = (S_func_007b2f20*)a1;
    p->f((int)this);
    ((void (__thiscall*)(void*, void*))(*(int*)((char*)this + 8)))(*(void**)((char*)this + 8), a1);
}
