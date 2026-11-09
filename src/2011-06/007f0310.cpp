// from server: 66% by atomic.potato
extern "C" void __cdecl sub_007f0210(void *);

struct S_func_007f0310 {
    char pad0[44];
    void *m_value;
    void f();
};

void S_func_007f0310::f()
{
    sub_007f0210(&m_value);
}
