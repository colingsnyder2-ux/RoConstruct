// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding[16];
    int active;
    void *allocation;
    void f();
};

void S::f()
{
    if (active)
        release(allocation);
}
