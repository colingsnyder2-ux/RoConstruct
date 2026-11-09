// from server: 100% by tester
struct CRobloxControlColorSelector {
    void SetColor(int value);
    void Invalidate();
    char pad_0[0x160];
    int m_field;
};

void CRobloxControlColorSelector::SetColor(int value) {
    if (this->m_field != value) {
        this->m_field = value;
        this->Invalidate();
    }
}
