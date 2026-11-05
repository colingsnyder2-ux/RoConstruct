// from server: 100% by colin
struct CXTPRibbonBar {
    char m_pad[0x27c];
    void* m_pField;
    int IsSomethingValid();
};

int CXTPRibbonBar::IsSomethingValid() {
    void* p = m_pField;
    if (p != 0 && *(int*)((char*)p + 0x44) != 0)
        return 1;
    return 0;
}
