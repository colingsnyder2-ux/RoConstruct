// from server: 100% by king_originala
typedef void (__thiscall *DestroyFn)(void *);
extern DestroyFn destroyStream;
extern "C" void __cdecl deallocate(void *);

struct S {
    void *destroy(unsigned int flags);
};

void *S::destroy(unsigned int flags)
{
    void *base = reinterpret_cast<char *>(this) - 0x50;
    destroyStream(base);
    if (flags & 1)
        deallocate(base);
    return base;
}
