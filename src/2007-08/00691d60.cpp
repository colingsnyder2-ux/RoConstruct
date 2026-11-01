// from server: 100% by colin
struct CXTThemeManagerStyle {
    void* m_unk0;
    void* m_unk4;
    void* m_unk8;
    void SetStyle(void* p);
};

void CXTThemeManagerStyle::SetStyle(void* p)
{
    if (m_unk4) {
        (*(void (__thiscall **)(void*, int))*(void**)m_unk4)(m_unk4, 1);
        m_unk4 = 0;
    }
    m_unk4 = p;
    *(void**)((char*)p + 4) = this;
    (*(void (__thiscall **)(void*))((char*)*(void**)m_unk4 + 4))(m_unk4);
    void* q = m_unk8;
    while (q) {
        (*(void (__thiscall **)(void*))((char*)*(void**)q + 8))(q);
        q = *(void**)((char*)q + 0x14);
    }
}
