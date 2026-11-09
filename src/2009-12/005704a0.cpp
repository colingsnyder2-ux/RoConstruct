// from server: 100% by atomic.potato
extern "C" void __declspec(dllimport) __stdcall InitializeCriticalSection(void *);
extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(void *);

struct CSHA1
{
    unsigned char data[0x19];
    void f();
};

void CSHA1::f()
{
    if (!data[0x18])
    {
        InitializeCriticalSection(this);
        data[0x18] = 1;
    }
    EnterCriticalSection(this);
}
