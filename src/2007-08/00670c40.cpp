// from server: 100% by colin
struct CXTPToolBar_CControlButtonExpand {
    void* sub_670BD0();
    void* method_670C40(int);
};

void* CXTPToolBar_CControlButtonExpand::method_670C40(int arg) {
    void* p = sub_670BD0();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
