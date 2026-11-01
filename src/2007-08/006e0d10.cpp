// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer {
    char pad0[0x134];
    int m_x;
    int f();
};

int CXTPDockingPaneTabbedContainer::f() {
    return reinterpret_cast<int>(this) - 0x134;
}
