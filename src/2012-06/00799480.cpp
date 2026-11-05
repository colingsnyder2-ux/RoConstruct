// from server: 68% by atomic.potato
struct S_func_00799480 {
    char pad[0x3c];
    void* m_field3c;
    void* f(int);
};

extern "C" void __stdcall sub_00982114(void*);
extern "C" void __stdcall sub_00591ef0();

void* S_func_00799480::f(int)
{
    sub_00982114(m_field3c);
    sub_00591ef0();
    if (reinterpret_cast<unsigned int&>(m_field3c) & 1) {
        sub_00982114(this);
    }
    return this;
}
