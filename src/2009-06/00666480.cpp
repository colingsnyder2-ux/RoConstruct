// from server: 48% by atomic.potato
struct S_func_00666480 {
    char pad0[0x98];
    int m_field98;
    int f(int arg);
};

int S_func_00666480::f(int arg)
{
    if (arg == 0) {
        S_func_00666480* p = (S_func_00666480*)((char*)this - 0x98);
        int* vtbl = *(int**)((char*)p + 0x40);
        int (*fn)(S_func_00666480*) = (int (*)(S_func_00666480*))vtbl;
        return fn(p);
    }
    return 0;
}
