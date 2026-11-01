// from server: 100% by atomic.potato
struct CXTPCommandBar {
    char pad[0x168];
    void* m_pSomething;
    void SetSomething(void* p);
};

extern "C" void __fastcall sub_7A7F1C(void* p);

void CXTPCommandBar::SetSomething(void* p) {
    if (m_pSomething) {
        sub_7A7F1C(m_pSomething);
    }
    m_pSomething = p;
}
