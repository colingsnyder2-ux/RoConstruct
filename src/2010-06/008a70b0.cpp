// from server: 100% by tester
struct CXTPDockingPaneAutoHidePanel {
    void func_006e0730(int, int);
    void func_0066f110(int);
    void* func_0071fa90(int, int);
    char pad[60];
};

void* CXTPDockingPaneAutoHidePanel::func_0071fa90(int a, int b)
{
    func_006e0730(a, b);
    *(int*)this = 0x7e211c;
    ((CXTPDockingPaneAutoHidePanel*)((char*)this + 0x38))->func_0066f110(0xa);
    return this;
}
