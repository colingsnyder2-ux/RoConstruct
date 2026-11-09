// from server: 100% by atomic.potato
struct S
{
};

void __cdecl f(void *p, int value)
{
    ((void (*)(int))*(void **)p)(value);
}
