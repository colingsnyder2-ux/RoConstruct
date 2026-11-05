// from server: 49% by atomic.potato
extern "C" void basic_string_copy(void*, const void*);

struct S_func_008e7850 {
    char pad[212];
    void* m_string;
    void f(void*);
};

void S_func_008e7850::f(void* target)
{
    basic_string_copy(target, m_string);
    *(char**)((char*)target + 0x1c) = *(char**)((char*)m_string + 0x1c);
}
