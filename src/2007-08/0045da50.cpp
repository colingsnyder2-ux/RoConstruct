// from server: 100% by colin
extern "C" void __cdecl func_0062ff26(void*);
extern "C" void __cdecl func_0062fc62(void*);

struct HH_CArray
{
    void* vtable;
    void* data;
    HH_CArray* destroy(unsigned int flags);
};

HH_CArray* HH_CArray::destroy(unsigned int flags)
{
    vtable = (void*)0x7941c0;
    if (data)
    {
        func_0062ff26(data);
    }
    if (flags & 1)
    {
        func_0062fc62(this);
    }
    return this;
}
