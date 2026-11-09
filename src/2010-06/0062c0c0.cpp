// from server: 84% by atomic.potato
extern "C" void __stdcall destroy_string(void *);
extern "C" void __cdecl release_string(void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)((char *)this + 12);
    if (p)
    {
        destroy_string(p);
        release_string(p);
    }
}
