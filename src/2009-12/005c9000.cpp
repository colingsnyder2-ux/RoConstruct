// from server: 61% by atomic.potato
extern "C" void basic_string_copy(void* destination, void* source);

struct S_func_005c9000 {
    char pad0[192];
    void* m_string;
    S_func_005c9000* f(S_func_005c9000* value);
};

S_func_005c9000* S_func_005c9000::f(S_func_005c9000* value)
{
    basic_string_copy(&m_string, value);
    value->m_string = m_string;
    return value;
}
