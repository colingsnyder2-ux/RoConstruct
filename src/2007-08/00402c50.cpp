// from server: 82% by colin
struct VCWorkspace_CComObject
{
    char pad[0x20];
    void* m_outer;
    char pad2[0xc];
    int m_refCount;
    int Release(int);
};

int VCWorkspace_CComObject::Release(int arg)
{
    VCWorkspace_CComObject* self = (VCWorkspace_CComObject*)arg;
    int result = --self->m_refCount;
    if (result == 0 && self != 0)
    {
        void* p = *(void**)((char*)self + 0x20);
        void** vtbl = *(void***)p;
        typedef void (__stdcall *Fn)(int);
        Fn fn = (Fn)vtbl[5];
        fn(1);
    }
    return result;
}
