// from server: 77% by colin
struct VCWorkspace_CComContainedObject {
    char pad[0x30];
    void* field30;

    void* func(void* arg);
};

void* VCWorkspace_CComContainedObject::func(void* arg)
{
    void* p = *(void**)((char*)arg + 0x30);
    void** vtbl = *(void***)p;
    void* (__stdcall *fn)(void*) = (void* (__stdcall *)(void*))vtbl[2];
    return fn(p);
}
