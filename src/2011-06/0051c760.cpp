// from server: 100% by atomic.potato
struct S
{
    char padding[16];
    int value;
    void *object;
    void f();
};

extern "C" void __cdecl release(void *);

void S::f()
{
    if (value != 0)
        release(object);
}
