// from server: 85% by colin
struct CMainFrame {
    char pad[0xe0];
    bool m_bFullScreen;
    char pad2[0xec - 0xe1];
    bool m_bSomething;
    char pad3[0xf4 - 0xed];
    char m_dropTarget[0x26c - 0xf4];
    char m_statusBar[0x100];

    void sub_430800();
    void sub_430ee0(int);
    void sub_68d590();
    void func_004313c0();
};

extern "C" void* __stdcall sub_62ff02();
extern "C" void __stdcall sub_63059e(void*, const char*, const char*, int);
extern "C" void __stdcall sub_630598(void*);
extern "C" void __stdcall sub_66dbe0(void*, const char*, void*, int);

extern const char str_78b110[];
extern const char str_78b11c[];
extern const char str_78a7b4[];

void CMainFrame::func_004313c0()
{
    void* p = sub_62ff02();
    void* q = *(void**)((char*)p + 4);
    int flag = m_bFullScreen ? 1 : 0;
    sub_63059e(q, str_78b110, str_78b11c, flag);
    if (m_bFullScreen) {
        sub_430800();
    } else {
        sub_66dbe0(m_dropTarget, str_78a7b4, this, 0);
    }
    if (m_bSomething) {
        sub_430ee0(0);
    }
    sub_630598(this);
    sub_68d590();
}
