// from server: 83% by atomic.potato
struct S
{
    void f(void** begin, void** end);
};

extern void G1_func_00749290(void*);

void S::f(void** begin, void** end)
{
    for (; begin != end; begin = (void**)((char*)begin + 0x14))
        G1_func_00749290(begin);
}
