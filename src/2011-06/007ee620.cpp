// from server: 67% by atomic.potato
struct S_func_004e9330
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = a1;
}

struct S
{
    void f(S_func_004e9330* a1);
};

void S::f(S_func_004e9330* a1)
{
    int a = *(int*)((char*)this);
    int b = *(int*)((char*)a1);
    ((void (__thiscall*) (void*, S_func_004e9330*))(*(int*)((char*)a + 8)))(this, a1);
    ((void (__thiscall*) (void*, int))(*(int*)((char*)b + 4)))(a1, *(int*)((char*)this));
}
