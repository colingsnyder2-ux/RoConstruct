// from server: 75% by atomic.potato
extern "C" void __cdecl Target(void *);

struct S
{
    void Set(void *);
};

void S::Set(void *value)
{
    if (*(void **)((char *)this + 0x90) == value)
        return;
    *(void **)((char *)this + 0x90) = value;
    Target((void *)0xe508f8);
}
