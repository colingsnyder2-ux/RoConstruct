// from server: 81% by atomic.potato
struct RefPropDescriptor
{
    void* __cdecl get(void*);
};

void* RefPropDescriptor::get(void* a)
{
    void* p = 0;
    p = this->get(a);
    if (p != 0)
    {
        p = *(void**)((char*)p + 0x140);
        if (p != 0)
            return *(void**)((char*)p + 0xd0);
    }
    return 0;
}
