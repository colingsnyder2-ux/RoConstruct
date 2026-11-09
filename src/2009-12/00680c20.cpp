// from server: 77% by atomic.potato
extern "C" void destroy_string(void *);

extern "C" void __cdecl release_object(void *);

struct S
{
    void __cdecl f(void *);
};

void __cdecl S::f(void *value)
{
    if (value)
    {
        destroy_string(value);
        release_object(value);
    }
}
