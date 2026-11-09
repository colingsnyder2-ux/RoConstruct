// from server: 100% by atomic.potato
struct S_func_00695700
{
    char pad[180];
    float* m_p;
    float f();
};

float S_func_00695700::f()
{
    return *(float*)((char*)m_p + 212);
}
