// from server: 100% by why2
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

struct S {
    void* handle;
    void f();
};

void S::f()
{
    void* h = handle;
    if (h != 0 && h != (void*)-1)
        CloseHandle(h);
}
