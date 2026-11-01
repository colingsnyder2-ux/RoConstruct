// from server: 100% by colin
struct Workspace {
    char pad[0x228];
    void* field_0x228;
    void* method_0x58;
    void* func(void* arg);
};

void* Workspace::func(void* arg)
{
    void* obj = *(void**)((char*)this - 0x228);
    void* fn = *(void**)((char*)obj + 0x58);
    void* self = (char*)this - 0x228;
    ((void (__thiscall*)(void*, void*))fn)(self, arg);
    return arg;
}
