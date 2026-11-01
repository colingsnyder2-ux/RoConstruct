// from server: 100% by king_originala
typedef void (__thiscall *StringDestructor)(void *);

extern StringDestructor destroyString;
extern void *profilerVtable[];
void __cdecl operator delete(void *);

struct Profiler
{
    void **vtable;
    char padding[0xC01C];
    char stringStorage[28];

    Profiler *__thiscall destroy(unsigned int flags);
};

Profiler *__thiscall Profiler::destroy(unsigned int flags)
{
    vtable = profilerVtable;
    destroyString(stringStorage);
    if (flags & 1)
        operator delete(this);
    return this;
}
