// from server: 46% by atomic.potato
extern "C" void __declspec(dllimport) __stdcall InitializeCriticalSection(void *);
extern "C" void __declspec(dllimport) __stdcall EnterCriticalSection(void *);
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(void *);

struct CSHA1
{
    unsigned char reserved[0x18];
    unsigned char locked;
    void Leave();
    void f();
};

void CSHA1::Leave()
{
    if (locked)
        LeaveCriticalSection(this);
}

void CSHA1::f()
{
    if (!locked)
    {
        InitializeCriticalSection(this);
        EnterCriticalSection(this);
    }
}

struct RakPeer
{
    char pad0[0xc];
    unsigned int field_c;
    char pad10[0x8];
    unsigned int field_18;
    char pad1c[0x530];
    CSHA1 sha;
    void func(unsigned int *a, unsigned int *b);
};

void RakPeer::func(unsigned int *a, unsigned int *b)
{
    sha.f();
    *a = field_18;
    *b = (field_c + 7) >> 3;
    sha.Leave();
}
