// from server: 84% by atomic.potato
extern "C" void __declspec(noreturn) __cdecl Target();

struct S
{
    void f(void*);
};

void S::f(void* value)
{
    if (reinterpret_cast<void**>(this)[46] != value)
    {
        reinterpret_cast<void**>(this)[46] = value;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xb8) = value;
        *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(0x00b95a88);
        Target();
    }
}
