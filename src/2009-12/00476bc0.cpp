// from server: 100% by atomic.potato
struct VCWorkspace_CComObject
{
    int f();
    char padding[0x20];
    void* field20;
};

int VCWorkspace_CComObject::f()
{
    void* p = field20;
    if (p)
        return *(int*)((char*)p + 0xA90);
    return 0;
}
