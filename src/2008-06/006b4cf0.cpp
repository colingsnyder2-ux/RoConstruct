// from server: 100% by Cezant64gamejr
struct CXTPCommandBar {
    char pad0[240];
    unsigned int m_flag;

    int f();
};

int CXTPCommandBar::f() {
    return (m_flag >> 22) & 1;
}
