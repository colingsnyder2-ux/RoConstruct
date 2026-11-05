// from server: 51% by atomic.potato
extern "C" void __stdcall BoundVerbDispatch(void *, void *);

struct BoundVerb
{
    int Get();
};

int BoundVerb::Get()
{
    int value = *(int *)((char *)this + 0x10);
    if (value != 0 && (value & 0x86b640) != 0)
        BoundVerbDispatch((char *)this + 0x10, *(void **)((char *)this + 8));
    return 0;
}
