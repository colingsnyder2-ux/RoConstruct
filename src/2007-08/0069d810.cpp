// from server: 100% by colin
struct CXTPPropertyGridItemColor {
    virtual void vf0();
    virtual void vf1(int);
    char pad_0x004[0x160];
    int m_nField_0x164;
    void OnInplaceButtonDown();
};

void CXTPPropertyGridItemColor::OnInplaceButtonDown()
{
    if (m_nField_0x164 != 0)
        vf1(1);
}
