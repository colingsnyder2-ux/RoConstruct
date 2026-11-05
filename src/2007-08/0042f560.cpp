// from server: 100% by colin
// roc 2007-08 0042f560  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042f560

struct CRobloxControlColorSelector {
    void SetColor(int value);
    void Invalidate();
    char pad_0[0x15c];
    int m_field;
};

void CRobloxControlColorSelector::SetColor(int value) {
    if (this->m_field != value) {
        this->m_field = value;
        this->Invalidate();
    }
}
