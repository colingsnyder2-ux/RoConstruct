// from server: 78% by atomic.potato
extern "C" int __stdcall CloseHandle(int);

struct S
{
    void f();
};

void S::f()
{
    CloseHandle(*(int *)((char *)this + 0x14));
    CloseHandle(**(int **)((char *)this + 0x0c));
    CloseHandle(**(int **)((char *)this + 0x10));
}
