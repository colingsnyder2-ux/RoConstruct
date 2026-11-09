// from server: 100% by tester
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long*, long);
extern "C" int __declspec(dllimport) __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct S
{
    void f();
};

void S::f()
{
    long result = InterlockedExchange((long*)((char*)this + 0x1a8), 1);
    if (!result)
    {
        PostMessageA(*(void**)((char*)this + 0x20), 0x469, 0, 0);
    }
}
