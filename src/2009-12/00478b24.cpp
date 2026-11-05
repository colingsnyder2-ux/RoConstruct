// from server: 70% by atomic.potato
extern "C" void __cdecl func_00424990(int, const char *, const char *);

struct S
{
    void *f();
};

void *S::f()
{
    func_00424990(0, "\x58\xac\x9a\x00", "\x1c\x1c\x9b\x00");
    return (void *)0x478a71;
}
