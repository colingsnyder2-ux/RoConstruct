// from server: 100% by atomic.potato
extern "C" void __stdcall Dispatch(void *);

struct S
{
    void Set(void *);
};

void S::Set(void *value)
{
    if (*(void **)((char *)this + 0xcd8) != value)
    {
        *(void **)((char *)this + 0xcd8) = value;
        Dispatch((void *)0xe2efc0);
    }
}
