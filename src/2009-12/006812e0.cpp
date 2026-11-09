// from server: 80% by atomic.potato
extern "C" void destroy_string(void *);
extern "C" void __cdecl release_object(void *);

struct S
{
    void *value;
    void f();
};

void S::f()
{
    void *p = *(void **)((char *)this + 12);
    if (p)
    {
        destroy_string(p);
        release_object(p);
    }
}
