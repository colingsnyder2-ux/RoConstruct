// from server: 100% by colin
struct CDataModelPropGrid {
    char pad0[0xec];
    unsigned char m_flag;
    void other(int);
    void alt();
    void f();
};

void CDataModelPropGrid::f() {
    if (m_flag)
        other(0);
    else
        alt();
}
