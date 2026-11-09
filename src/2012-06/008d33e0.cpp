// from server: 62% by atomic.potato
extern "C" void __stdcall sub_008d32e0(void*, float, int);

struct S_func_008d33e0 {
    char pad0[8];
    void* m_value;
    void* m_context;
    void f(int, float);
};

void S_func_008d33e0::f(int a, float b)
{
    void* value = m_value;
    if (value)
        value = (char*)value + 0x1c;
    sub_008d32e0(m_context, b, (int)value);
}
