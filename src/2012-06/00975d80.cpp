// from server: 70% by Intel
struct S_func_00975d80 {
    int m_refCount;
    int f(int* arg1, int* arg2);
};

int S_func_00975d80::f(int* arg1, int* arg2)
{
    int* v = arg2;
    int p = *v;
    if (p) {
        int* n = (int*)v[1];
        *n = p;
        *(int*)(p + 4) = (int)n;
    }
    --m_refCount;
    *v = 0;
    v[1] = 0;
    *arg1 = p;
    return p;
}
