// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer {
    char pad[0x1c0];
    int field_0x1c0;
    int getSomething();
    int func_006e23e0();
};

int CXTPDockingPaneTabbedContainer::func_006e23e0()
{
    if (getSomething() == 0)
        return 0;
    return field_0x1c0;
}
