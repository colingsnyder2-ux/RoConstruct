// from server: 100% by why2
struct CSHA1 {
    char pad0[24];
    char m_flag;
    void f();
};

extern "C" void (__stdcall *DeleteCriticalSection)(void*);

void CSHA1::f()
{
    if (m_flag != 0) {
        DeleteCriticalSection(this);
    }
}
