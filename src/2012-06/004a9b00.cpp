// from server: 32% by atomic.potato
struct DxUserInput
{
    char pad0[0x44];
    char m_cs[0x3c];
    int f(int value);
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __stdcall sub_4A8290();
extern "C" void __stdcall sub_B22648();
extern "C" void __stdcall sub_B221B8(void*);
extern "C" void __stdcall sub_B2263C();
extern "C" void __stdcall sub_B221B4(void*);

int DxUserInput::f(int value)
{
    sub_B22648();
    sub_B221B8(m_cs + 0x3c);
    sub_B2263C();
    sub_4A8290();
    sub_B221B4(m_cs + 0x3c);
    return value;
}
