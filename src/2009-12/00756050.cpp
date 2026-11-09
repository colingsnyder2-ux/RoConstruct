// from server: 62% by atomic.potato
extern "C" void __declspec(noreturn) __stdcall Function_0040c080(float);

struct S_func_00756050 {
    char pad0[864];
    float m_value;
    void f(float value);
};

void S_func_00756050::f(float value)
{
    if (m_value != value) {
        m_value = value;
        Function_0040c080(0xb9735c);
    }
}
