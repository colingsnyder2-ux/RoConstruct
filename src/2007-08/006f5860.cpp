// from server: 100% by colin
struct CXTPControlCustom {
    unsigned char m_reserved[0x170];
    int m_nState;
    void Update();
    void SetActive(int nType);
};

void CXTPControlCustom::SetActive(int nType) {
    if (nType == 2 && m_nState != 0) {
        Update();
    }
}
