// from server: 43% by atomic.potato
extern "C" void __stdcall copy_string(void*, void*);

struct S
{
    char pad[0x11c];
    char value[0x20];
    S* f(S* source);
};

S* S::f(S* source)
{
    copy_string((void*)(this + 0x11c), (void*)(source + 0x1c));
    *(void**)(source + 0x1c) = *(void**)(this + 0x11c + 0x1c);
    return source;
}
