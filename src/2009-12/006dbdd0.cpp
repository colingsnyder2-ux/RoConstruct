// from server: 46% by atomic.potato
struct S_func_006dbdd0 {
    char pad0[0x4c];
    S_func_006dbdd0* m_next;
    S_func_006dbdd0* f();
};

extern "C" int __stdcall sub_007f4aaa(void*, void*, void*, int, int);

S_func_006dbdd0* S_func_006dbdd0::f()
{
    S_func_006dbdd0* p = m_next;
    if (p == 0)
        return 0;
    while (sub_007f4aaa(p, (void*)0xaffe40, (void*)0xb36914, 0, 0) == 0) {
        p = p->m_next;
        if (p == 0)
            return 0;
    }
    return p;
}
