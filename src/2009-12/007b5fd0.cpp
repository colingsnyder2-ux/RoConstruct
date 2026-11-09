// from server: 48% by atomic.potato
struct S_func_007d8e70
{
    char pad0[36];
    int m_x;
    void f(int a1);
};

void S_func_007d8e70::f(int a1)
{
    m_x = (int)a1;
}

struct S_func_007d8da0
{
    void f(int a1);
};

void S_func_007d8da0::f(int a1)
{
}

struct S
{
    void f(int a1);
};

void S::f(int a1)
{
    int ebx = a1;
    S_func_007d8da0* edi = (S_func_007d8da0*)0;
    ((void (__thiscall*)(void*, int))(*(int**)this)[2])(this, ebx);
    ((void (__thiscall*)(S_func_007d8da0*, S*))0x7d8e70)(edi, this);
    ((void (__thiscall*)(S_func_007d8da0*, int))0x7d8da0)(edi, ebx);
}
