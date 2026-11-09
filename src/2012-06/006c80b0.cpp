// from server: 55% by atomic.potato
extern "C" void __cdecl f_004015a0(const char *, const void *, int, int);
extern "C" void __cdecl f_006c7f80();

struct S
{
    int f();
};

int S::f()
{
    f_004015a0("tUVW", (const void *)0x006c8010, 0, 0);
    f_006c7f80();
    return 0;
}
