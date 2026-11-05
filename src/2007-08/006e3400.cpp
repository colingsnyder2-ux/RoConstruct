// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer
{
    void func_006e2bd0(void*, int);
    void func_006e3400(void*, int);
};

void CXTPDockingPaneTabbedContainer::func_006e3400(void* p, int n)
{
    if (p != 0)
    {
        *(int*)((char*)this + 0x68) = n;
        *(int*)((char*)this + 0x58) = *(int*)((char*)p + 0x24);
        *(int*)((char*)this + 0x5c) = *(int*)((char*)p + 0x28);
        *(int*)((char*)this + 0x70) = *(int*)((char*)p + 0x3c);
        *(int*)((char*)this + 0x74) = *(int*)((char*)p + 0x40);
        *(int*)((char*)this + 0x78) = *(int*)((char*)p + 0x44);
        *(int*)((char*)this + 0x7c) = *(int*)((char*)p + 0x48);
        func_006e2bd0(p, 1);
        (*(void(__thiscall**)(void*, void*, int, int))(*(int*)this + 0x13c))(this, p, 1, 1);
    }
}
