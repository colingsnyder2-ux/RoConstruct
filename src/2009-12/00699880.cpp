// from server: 97% by atomic.potato
extern "C" void* __cdecl sub_006997F0(void*);

struct RefPropDescriptor
{
    void* __cdecl get(void*);
};

void* __cdecl RefPropDescriptor::get(void* value)
{
    void* p = sub_006997F0(value);
    if (p != 0)
    {
        p = *(void**)((char*)p + 0x140);
        if (p != 0)
            return *(void**)((char*)p + 0xd0);
    }
    return 0;
}
