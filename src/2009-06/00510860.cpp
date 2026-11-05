// from server: 100% by why2
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct CSHA1 {
    char pad0[0x18];
    char m_flag;
    void f();
};

void CSHA1::f()
{
    if (m_flag != 0)
        LeaveCriticalSection(this);
}
