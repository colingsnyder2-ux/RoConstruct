// from server: 100% by atomic.potato
typedef void* CRITICAL_SECTION;

extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(CRITICAL_SECTION*);

struct CSHA1
{
    unsigned char reserved[0x18];
    unsigned char locked;
    void Leave();
};

void CSHA1::Leave()
{
    if (locked)
        LeaveCriticalSection((CRITICAL_SECTION*)this);
}
