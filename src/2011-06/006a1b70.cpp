// from server: 95% by atomic.potato
extern "C" int __cdecl f(void *, const char *);

struct S
{
};

unsigned char __cdecl f(const char *p)
{
    return ::f(0, p) != 0;
}
