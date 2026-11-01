// from server: 100% by atomic.potato
extern "C" void __declspec(dllimport) __cdecl free(void *);

struct S
{
    void f();
};

void S::f()
{
    free(*(void **)this);
}
