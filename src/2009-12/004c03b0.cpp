// from server: 48% by atomic.potato
struct S_func_00484cb0 {
    char pad0[2088];
    int m_x;
    int f();
};

struct S {
    char pad0[4];
    int m_field4;
    char pad1[0x1c];
    int m_field24;
    int g();
};

int S::g()
{
    if (m_field4 != 0 && m_field24 != 0)
    {
        S_func_00484cb0* p = *(S_func_00484cb0**)((char*)this - 0x54);
        int r = p->f();
        ((void (__thiscall*)(void*, int))0x580280)((void*)r, 0);
    }
    return 0;
}
