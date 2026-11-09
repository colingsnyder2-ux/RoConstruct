// from server: 100% by king_originala
extern void (__thiscall *textureDestructor)(void *);
extern "C" void __cdecl release(void *);

struct S {
    void *unused;
    void *object;
    void *count;
    void f();
};

void S::f()
{
    void *p = object;
    if (p) {
        textureDestructor(static_cast<char *>(p) + 0x20c);
        release(p);
    }
    release(count);
}
