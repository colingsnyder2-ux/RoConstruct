// from server: 100% by EspClaude
// roc 2007-08 006b3a50  unit: CXTPControlComboBoxGalleryPopupBar  size: 173 bytes
// Target facts used: this->[+0x180] combo pointer (ebx), combo vtable +0x74 (int, no args)
// and +0x98 (void); [this+0xc8] int index passed to thiscall 0x644720 (GetControl(int),
// ret 4); 0x6b3960 thiscall no-arg helper; 0x647530 base thiscall (nChar,lParam) ret 8;
// this vtable +0x210 called with (combo, nChar, lParam). VK_ESCAPE 0x1b, VK_TAB 9, VK_RETURN 0xd;
// return value for VK_RETURN is (nChar - 0xc) == 1.

class CXTPControl;

class CXTPControlComboBox
{
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual int IsDroppedFocus();       // +0x74
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void OnExecute();           // +0x98
};

class CXTPPopupBarBase
{
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void b57();
    virtual void b58();
    virtual void b59();
    virtual void b60();
    virtual void b61();
    virtual void b62();
    virtual void b63();
    virtual void b64();
    virtual void b65();
    virtual void b66();
    virtual void b67();
    virtual void b68();
    virtual void b69();
    virtual void b70();
    virtual void b71();
    virtual void b72();
    virtual void b73();
    virtual void b74();
    virtual void b75();
    virtual void b76();
    virtual void b77();
    virtual void b78();
    virtual void b79();
    virtual void b80();
    virtual void b81();
    virtual void b82();
    virtual void b83();
    virtual void b84();
    virtual void b85();
    virtual void b86();
    virtual void b87();
    virtual void b88();
    virtual void b89();
    virtual void b90();
    virtual void b91();
    virtual void b92();
    virtual void b93();
    virtual void b94();
    virtual void b95();
    virtual void b96();
    virtual void b97();
    virtual void b98();
    virtual void b99();
    virtual void b100();
    virtual void b101();
    virtual void b102();
    virtual void b103();
    virtual void b104();
    virtual void b105();
    virtual void b106();
    virtual void b107();
    virtual void b108();
    virtual void b109();
    virtual void b110();
    virtual void b111();
    virtual void b112();
    virtual void b113();
    virtual void b114();
    virtual void b115();
    virtual void b116();
    virtual void b117();
    virtual void b118();
    virtual void b119();
    virtual void b120();
    virtual void b121();
    virtual void b122();
    virtual void b123();
    virtual void b124();
    virtual void b125();
    virtual void b126();
    virtual void b127();
    virtual void b128();
    virtual void b129();
    virtual void b130();
    virtual void b131();
    virtual int ProcessKey(CXTPControlComboBox* pCombo, unsigned int nChar, long lParam);  // +0x210
    CXTPControl* GetControl(int nIndex);                         // 0x644720
    int OnHookKeyDown(unsigned int nChar, long lParam);          // 0x647530
    char pad4[0xc8 - 4];
    int m_nSelected;                                             // +0xc8
    char padcc[0x180 - 0xcc];
    CXTPControlComboBox* m_pControlCombo;                        // +0x180
};

class CXTPControlComboBoxGalleryPopupBar : public CXTPPopupBarBase
{
public:
    CXTPControl* GetGalleryItem();                               // 0x6b3960
    int OnHookKeyDown(unsigned int nChar, long lParam);
};

int CXTPControlComboBoxGalleryPopupBar::OnHookKeyDown(unsigned int nChar, long lParam)
{
    CXTPControlComboBox* pCombo = m_pControlCombo;
    if (!pCombo)
        return CXTPPopupBarBase::OnHookKeyDown(nChar, lParam);

    if (nChar == 0x1b)
    {
        if (pCombo->IsDroppedFocus())
            return 0;
        return CXTPPopupBarBase::OnHookKeyDown(nChar, lParam);
    }
    if (nChar == 9)
        return 0;
    if (nChar == 0xd && GetControl(m_nSelected) == GetGalleryItem())
    {
        m_pControlCombo->OnExecute();
        return 1;
    }
    return ProcessKey(pCombo, nChar, lParam);
}
