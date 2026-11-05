// from server: 38% by colin
struct CXTPRibbonGroupPopupToolBar {
    char pad[0x1a0];
    int m_nLocked;
    char pad2[0x10];
    char m_rect1[0x10];
    char pad3[0x28];
    int m_nX;
    char pad4[0x4];
    int m_nY;
    char pad5[0x50];
    void* m_pWnd1;
    void* m_pWnd2;
    char pad6[0x4];
    void* m_pWnd3;

    void f(int* pOut);
};

extern "C" void __stdcall SetRectEmpty(void*);
extern "C" void __stdcall sub_630946(void*);
extern "C" void __stdcall sub_630940(void*);
extern "C" void* __stdcall sub_643a40();
extern "C" void __stdcall sub_680550(void*, void*, void*);
extern "C" void __stdcall sub_6805d0(void*);
extern "C" void __stdcall sub_716d30(void*, void*, void*, void*, void*, void*);

void CXTPRibbonGroupPopupToolBar::f(int* pOut)
{
    void* pWnd;
    void* pWnd2;
    int nX;
    int nY;
    int nResult;
    int nResult2;
    int nRect[4];

    m_nLocked = 1;

    sub_630946(&pWnd);

    pWnd2 = sub_643a40();

    nResult = (*(int (__stdcall**)(void*, void*))(*(int*)pWnd2 + 0xd8))(pWnd2, this);

    sub_680550(&pWnd, &nResult, &pWnd2);

    (*(void (__stdcall**)(void*))(*(int*)this + 0x1d0))(this);

    nResult2 = (*(int (__stdcall**)(void*))(*(int*)m_pWnd3 + 0x210))(m_pWnd3);

    (*(void (__stdcall**)(void*, int*))(*(int*)m_pWnd1 + 0x74))(m_pWnd1, &nX);

    nResult = (*(int (__stdcall**)(void*, int*))(*(int*)m_pWnd1 + 0x7c))(m_pWnd1, &nX);

    nRect[0] = 0;
    nRect[1] = 0;
    nRect[2] = 0;
    nRect[3] = 0;

    sub_716d30(m_pWnd1, (void*)nResult, (void*)nRect[0], (void*)nRect[1], (void*)nRect[2], (void*)nRect[3]);

    (*(void (__stdcall**)(void*))(*(int*)m_pWnd1 + 0x78))(m_pWnd1);

    SetRectEmpty(&m_rect1);

    nX = m_nX + m_nY + nResult;
    nY = nResult2 - 7;

    m_nLocked = 0;

    pOut[0] = nX;
    pOut[1] = nY;

    sub_6805d0(&nRect);

    sub_630940(&nX);
}
