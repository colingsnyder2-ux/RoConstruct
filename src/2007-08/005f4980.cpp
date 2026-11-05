// from server: 100% by colin
struct RefPropDescriptor {
    void* getset;
    void* getValue(void* object);
};

void* RefPropDescriptor::getValue(void* object)
{
    void* p = *(void**)((char*)this + 0x1c);
    void** vtbl = *(void***)p;
    void* result = ((void* (__thiscall*)(void*, void*))vtbl[1])(p, object);
    if (result)
        return (char*)result + 4;
    return 0;
}
