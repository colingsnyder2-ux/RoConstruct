// from server: 95% by atomic.potato
extern "C" void __cdecl function_0040c080(void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    if (value != *(void **)((char *)this + 0xac))
    {
        *(void **)((char *)this + 0xac) = value;
        function_0040c080((void *)0x00b7e580);
    }
}
