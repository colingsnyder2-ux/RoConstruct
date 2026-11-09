// from server: 55% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    reinterpret_cast<void (__thiscall *)(char *, void *)>(0x760400)(
        reinterpret_cast<char *>(this) - 0xb8,
        reinterpret_cast<char *>(this) + 0x64);
}
