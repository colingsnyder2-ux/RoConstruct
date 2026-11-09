// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall CloseHandle(void *);

struct S {
    void *handle;
    void f();
};

void S::f()
{
    void *h = handle;
    if (h != 0 && h != (void *)-1)
        CloseHandle(h);
}
