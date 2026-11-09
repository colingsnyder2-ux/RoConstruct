// from server: 100% by colin
struct CXTPDockingPaneAutoHidePanel {
    void* field_0;
    int method1(void*);
    int method2(int);
};

int CXTPDockingPaneAutoHidePanel::method1(void* arg)
{
    int* self_vtbl = *(int**)this;
    int v = (*(int (__thiscall**)(void*, void*))(*(int*)arg + 0x3c))(arg, arg);
    return (*(int (__thiscall**)(CXTPDockingPaneAutoHidePanel*, int))self_vtbl)(this, v);
}
