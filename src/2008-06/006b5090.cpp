// from server: 100% by tester
struct CXTPCommandBar {
    unsigned char padding[0xec];
    unsigned int m_nFlags;
    void ApplyFlags(unsigned int set, unsigned int clear);
};

void CXTPCommandBar::ApplyFlags(unsigned int set, unsigned int clear) {
    m_nFlags = (m_nFlags | set) & ~clear;
}
