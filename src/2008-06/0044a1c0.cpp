// from server: 100% by king_originala
typedef void (__thiscall *CleanupFunction)(void *);
extern CleanupFunction cleanup;

void __cdecl operator delete(void *);

struct S {
    void destroy();
    S *f(unsigned int flags);
};

S *S::f(unsigned int flags)
{
    cleanup(reinterpret_cast<char *>(this) + 0x94);
    destroy();
    if (flags & 1)
        operator delete(this);
    return this;
}
