// from server: 40% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct S {
    int m_8;
    int f(int*, int*);
};

int S::f(int* a, int* b)
{
    S_func_006cb2b0* p;
    int* q;
    int (*fn)(int*);

    if (a != 0)
        p = (S_func_006cb2b0*)((char*)a - 0x1c);
    else
        p = 0;

    q = p->f();
    fn = *(int (**)(int*))((char*)this + 8);
    return fn((int*)*b);
}
