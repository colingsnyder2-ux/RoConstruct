// from server: 95% by atomic.potato
extern "C" void __cdecl CallTarget(const char *);

struct S
{
    void Set(void *);
};

void S::Set(void *value)
{
    if (*((void **)((char *)this + 0x98)) != value)
    {
        *((void **)((char *)this + 0x98)) = value;
        CallTarget("QSUVW");
    }
}
