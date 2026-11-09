// from server: 72% by atomic.potato
extern "C" void * __cdecl function_52acb0();

struct T
{
    int function_6c8100(void *);
};

struct S
{
};

void * __cdecl f(void *p)
{
    if (p)
    {
        void *q = *((void **)p + 3);
        void *r = function_52acb0();
        if (((T *)q)->function_6c8100(r))
            return (char *)p - 0x1c;
    }
    return 0;
}
