// from server: 100% by atomic.potato
struct CXTPPropertyGrid {
    void sub_84eef0();
    int sub_9266ca();
    void sub_84efa0();
};

void CXTPPropertyGrid::sub_84efa0()
{
    sub_84eef0();
    void** vtbl = *(void***)this;
    ((void (__thiscall*)(CXTPPropertyGrid*, int))vtbl[0x160 / 4])(this, 0);
    void** vtbl2 = *(void***)this;
    int r = sub_9266ca();
    ((void (__thiscall*)(CXTPPropertyGrid*, int, int))vtbl2[0x154 / 4])(this, 1, r);
}
