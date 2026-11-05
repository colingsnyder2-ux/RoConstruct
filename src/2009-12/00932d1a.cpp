// from server: 44% by atomic.potato
extern "C" void __cdecl f(void *, unsigned int, unsigned int, const char *);

struct S
{
    void f();
};

void S::f()
{
    char buffer[0x114];
    ::f(buffer, 0x14, 6, "$SV3");
}
