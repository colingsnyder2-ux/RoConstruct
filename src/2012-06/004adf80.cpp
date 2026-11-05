// from server: 85% by atomic.potato
extern "C" void destroy_string(void *);

extern "C" void __cdecl function_982114(void *);

struct S
{
    void *data;
    void *reserved1;
    void *reserved2;
    void *value;
    void f();
};

void S::f()
{
    void *p = value;
    if (p)
    {
        destroy_string((char *)p + 12);
        function_982114(p);
    }
}
