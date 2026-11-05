// from server: 24% by atomic.potato
struct S_func_007e8280 {
    char pad0[8];
    int m_first;
    int m_last;
    int m_result;
    int m_func;
    void __cdecl f(int* first, int* last, int* result, int func);
};

void S_func_007e8280::f(int* first, int* last, int* result, int func)
{
    int* p = first;
    while (p != last) {
        int (*fn)(int) = (int (*)(int))func;
        fn(*p);
        p += 2;
    }
    result[0] = (int)first;
    result[1] = (int)last;
}
