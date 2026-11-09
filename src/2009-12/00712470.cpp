// from server: 61% by atomic.potato
struct S_func_00712470 {
    char pad0[24];
    void* m_field18;
    char pad1[4];
    void* m_field20;
};

bool f_00712470(S_func_00712470* arg)
{
    if (arg == 0)
        return false;
    S_func_00712470* p20 = (S_func_00712470*)arg->m_field20;
    if (p20 == 0)
        return false;
    S_func_00712470* p18 = (S_func_00712470*)p20->m_field18;
    if (p18 == 0)
        return false;
    if ((char*)p18 - 8 == 0)
        return false;
    S_func_00712470* q;
    if (p18 != 0)
        q = (S_func_00712470*)((char*)p18 - 8);
    else
        q = 0;
    S_func_00712470* r = (S_func_00712470*)q->m_field20;
    if (r == 0)
        return false;
    if ((char*)r - 8 == 0)
        return false;
    return true;
}
