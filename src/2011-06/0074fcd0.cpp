// from server: 26% by atomic.potato
struct S_func_0074fcd0 {
    char pad0[0xc4];
    unsigned short m_c4;
    unsigned short m_c6;
    void f(int);
};

extern "C" void __stdcall sub_0062d5f0();
extern "C" void __stdcall sub_00600fa0();

void S_func_0074fcd0::f(int a)
{
    sub_0062d5f0();
    *(int*)((char*)this + 0) = 0xa95b9c;
    *(int*)((char*)this + 4) = 0xa95b94;
    *(int*)((char*)this + 0x18) = 0xa95b88;
    *(int*)((char*)this + 0x1c) = 0xa95b7c;
    *(int*)((char*)this + 0x90) = 0xa95b74;
    m_c6 = 0;
    m_c4 = 0;
    sub_00600fa0();
}
