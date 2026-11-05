// from server: 100% by atomic.potato
struct S_00715930 {
    char pad0[180];
    int m_ptr;
    float f();
};

float S_00715930::f()
{
    return *(float *)(m_ptr + 164);
}
