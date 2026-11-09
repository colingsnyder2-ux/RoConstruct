// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall CryptDestroyKey(void *);
extern "C" int __declspec(dllimport) __stdcall CryptReleaseContext(void *, unsigned long);

struct S
{
    void *context;
    void *key;
    void f();
};

void S::f()
{
    CryptDestroyKey(key);
    CryptReleaseContext(context, 0);
}
