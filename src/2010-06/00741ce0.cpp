// from server: 71% by atomic.potato
struct Value
{
    void copy(void *);
};

struct S
{
    void __cdecl f(Value *, Value *);
};

void S::f(Value *begin, Value *end)
{
    char *p = (char *)begin;
    char *last = (char *)end;

    if (p != last)
    {
        do
        {
            ((Value *)p)->copy((void *)((char *)end + 0x18));
            *(void **)(p + 0x20) = *(void **)((char *)end + 0x20);
            p += 0x28;
        } while (p != last);
    }
}
