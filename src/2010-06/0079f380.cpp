// from server: 100% by atomic.potato
typedef unsigned long HCRYPTPROV;
typedef unsigned long HCRYPTKEY;
typedef int BOOL;

extern "C" BOOL __declspec(dllimport) __stdcall CryptDestroyKey(HCRYPTKEY);
extern "C" BOOL __declspec(dllimport) __stdcall CryptReleaseContext(HCRYPTPROV, unsigned long);

struct S
{
    HCRYPTPROV context;
    HCRYPTKEY key;
    void f();
};

void S::f()
{
    CryptDestroyKey(key);
    CryptReleaseContext(context, 0);
}
