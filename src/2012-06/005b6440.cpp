// from server: 100% by tester
struct S
{
    char padding[8];
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
