// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer {
    char pad[0x14];
    int field_14;
    char pad2[0x140 - 0x18];
    int field_140;
    void sub_62ff4a(int);
    void func_006e0bd0(int*);
};

void CXTPDockingPaneTabbedContainer::func_006e0bd0(int* param)
{
    field_14 = param[5];
    field_140 = 1;
    if (param[6] == 5) {
        if (*(int*)((char*)this - 0x34) != 0) {
            ((CXTPDockingPaneTabbedContainer*)((char*)this - 0x54))->sub_62ff4a(0);
        }
    }
}
