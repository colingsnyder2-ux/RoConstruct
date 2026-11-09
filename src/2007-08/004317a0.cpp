// from server: 34% by colin
// roc 2007-08 004317a0  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004317a0

extern "C" {
    void __stdcall sub_62FF4A();
    void __stdcall sub_68D500();
    void __stdcall sub_688440();
    void __stdcall sub_688D60();
    void __stdcall sub_430EE0();
    void __stdcall sub_430090();
    void __stdcall sub_42EB70();
    void __stdcall sub_42EBB0();
    void __stdcall sub_4310A0();
    void* __stdcall sub_77DD98();
}

struct CXTPFrameWndBase {
    char pad_0000[0xec];
    unsigned char m_bFlagEC;
    unsigned char m_bFlagED;
    char pad_00ee[0x02];
    char m_dataF0[0x17c];
    char m_data26C[0x15c];
    char m_data3C8[0x04];

    void OnSomething(int arg);
};

void CXTPFrameWndBase::OnSomething(int arg) {
    if (m_bFlagEC != 0 && m_bFlagED == 0) {
        sub_62FF4A();
        sub_430EE0();
        sub_68D500();
        sub_688440();
        sub_77DD98();
        sub_688D60();
        if (0) {
            sub_430090();
        } else {
            sub_42EB70();
            sub_42EBB0();
        }
        m_bFlagEC = 0;
        sub_4310A0();
    }
}
