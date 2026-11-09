// from server: 100% by king_originala
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

struct S {
    char padding[0x104];
    void* instance;
    int f();
};

int S::f()
{
    if (instance &&
        __RTDynamicCast(instance, 0, (void*)0x92907C, (void*)0x9353EC, 0))
        return 1;
    return 0;
}
