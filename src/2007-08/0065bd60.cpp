// from server: 100% by colin
struct CXTPReportControl {
    char pad[0xc4];
    int m_nValue;
    void SetValue(int n);
};

void CXTPReportControl::SetValue(int n) {
    if (n < 1)
        n = 1;
    m_nValue = n;
}
