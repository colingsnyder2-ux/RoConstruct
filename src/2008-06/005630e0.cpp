// from server: 100% by atomic.potato
extern "C" void __declspec(dllimport) __stdcall LeaveCriticalSection(void *);
extern "C" int __declspec(dllimport) __stdcall ReleaseMutex(void *);

struct ContentProvider {
    int value;
    unsigned char flag;
    int count;
    void f();
};

void ContentProvider::f()
{
    if (--count != 0)
        return;

    if (flag)
        ReleaseMutex((void *)value);
    else
        LeaveCriticalSection((void *)value);
}
