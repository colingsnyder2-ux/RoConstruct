// from server: 85% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl target(void);

void S::f()
{
    if (*reinterpret_cast<int *>(this) == 1)
        *reinterpret_cast<int *>(this) = 0;
    reinterpret_cast<void (__cdecl *)(void)>(target)();
}
