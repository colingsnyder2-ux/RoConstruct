// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long volatile *, long);
extern "C" unsigned long __declspec(dllimport) __stdcall WaitForSingleObject(void *, unsigned long);
extern "C" int __declspec(dllimport) __stdcall CloseHandle(void *);

struct S
{
    void *m14;
    void f();
};

void S::f()
{
    void *h = (void *)InterlockedExchange((long volatile *)((char *)this + 0x14), 0);
    if (h != 0)
    {
        WaitForSingleObject(h, (unsigned long)-1);
        CloseHandle(h);
    }
}
