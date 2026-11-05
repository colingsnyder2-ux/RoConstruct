// from server: 61% by atomic.potato
extern "C" void std_string_copy(void*, const void*);

struct S_func_00577940
{
    char pad[224];
    char m_string[32];
    void* f(void* p);
};

void* S_func_00577940::f(void* p)
{
    std_string_copy(p, m_string);
    *(int*)((char*)p + 28) = *(int*)(m_string + 28);
    return p;
}
