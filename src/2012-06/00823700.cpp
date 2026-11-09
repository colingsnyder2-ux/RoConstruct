// from server: 100% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(int*);
    void __thiscall method(int* p);
};

void __thiscall S::method(int* p)
{
    S_func_00750a60* obj;
    if (p != 0)
        obj = (S_func_00750a60*)((char*)p - 0x1c);
    else
        obj = 0;
    int* r = obj->f();
    m_fn(r);
}
