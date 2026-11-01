// from server: 100% by atomic.potato
extern "C" void __stdcall CallTarget(int, int);

struct S
{
    int value;
    int *link;
    int handle;
    int enabled;
    void f();
};

void S::f()
{
    if (link != 0)
        link[1] = value;

    if (enabled != 0)
        CallTarget(0, handle);
}
