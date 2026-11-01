// from server: 76% by colin
struct VCBrowserViewExternal_CComObjectNoLock
{
    void* construct(int);
};

void* VCBrowserViewExternal_CComObjectNoLock::construct(int arg)
{
    *(int*)((char*)this + 0x18) = 0;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0xc) = 0;
    *(int*)((char*)this + 8) = 0x78595c;
    *(short*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this) = 0x785c84;
    *(int*)((char*)this + 4) = 0x785c6c;
    *(int*)((char*)this + 8) = 0x785c48;
    *(int*)((char*)this + 0x14) = 0x785c20;
    int* p = *(int**)0x8bae44;
    int* vt = *(int**)p;
    void (__stdcall *fn)() = (void (__stdcall*)())*(int*)((char*)vt + 4);
    fn();
    return this;
}
