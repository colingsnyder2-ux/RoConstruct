// from server: 100% by atomic.potato
struct S_func_0074a720
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void f();
};

extern "C" void __cdecl sub_0080a058(void*);

struct S_func_0067db40
{
    void* m_00;
    char pad_04[0x18];
    void* m_1c;
    char pad_20[0x74];
    void* m_94;
    void* f(unsigned int);
};

void* S_func_0067db40::f(unsigned int flags)
{
    m_00 = (void*)0xa9e58c;
    m_1c = (void*)0xa9e570;
    m_94 = (void*)0xa9e554;
    ((S_func_0074a720*)this)->f();
    if (flags & 1)
        sub_0080a058(this);
    return this;
}
