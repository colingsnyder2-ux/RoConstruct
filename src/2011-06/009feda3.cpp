// from server: 68% by atomic.potato
extern "C" void __cdecl func_0080b1d8(void *, unsigned int, unsigned int, const void *);

struct S
{
    void f();
};

void S::f()
{
    char *p = reinterpret_cast<char *>(this) + 0x38;
    func_0080b1d8(p, 0xC, 4, reinterpret_cast<const void *>(0x6DC720));
}
