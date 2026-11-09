// from server: 65% by atomic.potato
struct S_func_006f4840 {
    char pad0[252];
    char m_data[36];
    int f(S_func_006f4840* value);
};

extern "C" void sub_005f3900(void*, void*);

int S_func_006f4840::f(S_func_006f4840* value)
{
    char* source = m_data;
    sub_005f3900(value, source);
    *(float*)(value->m_data + 36) = *(float*)(source + 36);
    *(float*)(value->m_data + 40) = *(float*)(source + 40);
    *(float*)(value->m_data + 44) = *(float*)(source + 44);
    return (int)value;
}
