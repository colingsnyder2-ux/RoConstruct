// from server: 100% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" BOOL __declspec(dllimport) __stdcall CryptDestroyKey(DWORD);
extern "C" BOOL __declspec(dllimport) __stdcall CryptReleaseContext(DWORD, DWORD);

struct S
{
    DWORD key;
    DWORD context;
    void f();
};

void S::f()
{
    CryptDestroyKey(context);
    CryptReleaseContext(key, 0);
}
