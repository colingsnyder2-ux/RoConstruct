// from server: 100% by colin
struct CXTPDockingPaneAutoHidePanel {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    void sub_630436();
    void sub_6de610();
};

void CXTPDockingPaneAutoHidePanel::sub_6de610() {
    if (field20 != 0) {
        (*(void (__thiscall**)(CXTPDockingPaneAutoHidePanel*))(*(int*)this + 0x68))(this);
    }
    sub_630436();
}
