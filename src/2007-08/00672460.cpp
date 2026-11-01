// from server: 100% by colin
struct CXTPControlColorSelector {
    char pad[0x168];
    int m_nValue;
    void SetValue(int nValue);
};

extern "C" void __stdcall sub_63a690(int);

void CXTPControlColorSelector::SetValue(int nValue) {
    if (m_nValue != nValue) {
        m_nValue = nValue;
        sub_63a690(1);
    }
}
