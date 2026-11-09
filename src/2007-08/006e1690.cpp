// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer
{
    char pad[0x1a4];
    int field_1a4;
    void func_006e1690(int);
};

extern void G1_func_0063023e();

void CXTPDockingPaneTabbedContainer::func_006e1690(int)
{
    field_1a4 = 0;
    G1_func_0063023e();
}
