// from server: 100% by atomic.potato
extern "C" int __declspec(dllimport) __stdcall CloseHandle(int);

struct S
{
    int handle;
    void f();
};

void S::f()
{
    int value = handle;
    if (value != 0 && value != -1)
        CloseHandle(value);
}
