// from server: 100% by atomic.potato
extern "C" void __cdecl free(void *p);

struct CXTPPropertyGridItemBool
{
    void Destructor();
    void* Cleanup(int bDelete);
};

void* CXTPPropertyGridItemBool::Cleanup(int bDelete)
{
    if (*(void **)((char *)this + 0x130))
    {
        free(*(void **)((char *)this + 0x130));
    }
    void *p = *(void **)((char *)this + 0x124);
    *(void **)((char *)this + 0x130) = 0;
    *(void **)((char *)this + 0x134) = 0;
    *(void **)((char *)this + 0x138) = 0;
    free(p);
    Destructor();

    if (bDelete & 1)
    {
        free(this);
    }

    return this;
}
