// from server: 100% by why2
struct P8ModelInstance_GetSetImpl
{
    char pad[0x1d8];
    void* ptr;
    bool get();
};

bool P8ModelInstance_GetSetImpl::get()
{
    void* p = ptr;
    if (p)
    {
        return ((bool (__thiscall*)(void*))((*(void***)p)[0x38 / 4]))(p);
    }
    return false;
}
