// from server: 32% by atomic.potato
struct S_func_00752c60 {
    char pad0[4];
    int m_x;
    int* f();
};

int* S_func_00752c60::f()
{
    return &m_x;
}

struct S_func_0070b3d0 {
    int f(int*);
};

struct Kernel {
    char pad0[24];
    void* m_data;
    int* f(int);
};

int* __cdecl func_00752c60();

int* Kernel::f(int value)
{
    int edi;
    int* p;
    S_func_0070b3d0* level = (S_func_0070b3d0*)((char*)m_data + 0x30);
    edi = *(int*)((char*)m_data + 0x34);
    p = func_00752c60();
    *p = edi;
    level->f(&value);
    return p;
}
