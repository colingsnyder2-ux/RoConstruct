// from server: 57% by atomic.potato
struct S_func_00950720 {
    void *m_pad[6];
    int f(void *, void *);
};

int S_func_00950720::f(void *a, void *b)
{
    int **v = *(int ***)a;
    return ((int (__thiscall *)(void *, void *))v[3])(m_pad[6], b);
}
