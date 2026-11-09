// from server: 100% by colin
struct CXTPDockingPaneOffice2003Theme {
    CXTPDockingPaneOffice2003Theme* construct();
};

extern void func_006eb270();

CXTPDockingPaneOffice2003Theme* CXTPDockingPaneOffice2003Theme::construct()
{
    func_006eb270();
    *(int*)((char*)this + 0x23c) = 0;
    *(int*)((char*)this + 0x240) = 0;
    *(int*)this = 0x7da80c;
    *(int*)((char*)this + 0x7c) = 3;
    return this;
}
