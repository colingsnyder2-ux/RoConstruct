// from server: 22% by TrollStein
struct CXTPCommandBarAnimation {
    void* m_pCommandBar;
    char m_pad[0x8];
    int m_nState;
    void* m_pAnimateInfo;
    void* m_pAnimateInfo2;
    char m_pad2[0x18];
    void* m_pCommandBar2;
    void Draw(int, int);
};

extern "C" void* __stdcall CreateCompatibleBitmap(void*, int, int);
extern "C" void* __stdcall CreateRectRgnIndirect(void*);
extern "C" void* __stdcall SelectObject(void*, void*);
extern "C" int __stdcall CopyRect(void*, void*, void*, void*);
extern "C" int __stdcall InvalidateRect(void*, void*, int);

extern "C" void __fastcall sub_63022c(void*);
extern "C" void __fastcall sub_630946(void*);
extern "C" void __fastcall sub_680000(void*);
extern "C" void __fastcall sub_7383e2(void*);
extern "C" void __fastcall sub_7383dc(void*);
extern "C" void __fastcall sub_73850e(void*, void*);
extern "C" void __fastcall sub_63d780(void*, void*);
extern "C" void __fastcall sub_63d7c0(void*, int, int, int, int, int, int, int);
extern "C" void __fastcall sub_647fc0(int, int, int, void*);
extern "C" void __fastcall sub_630238(void*, int);
extern "C" void __fastcall sub_630940(void*);
extern "C" void __fastcall sub_41f680(void*);
extern "C" void __fastcall sub_62fc62(void*);
extern "C" void* __fastcall sub_62fef6(int);
extern "C" int __fastcall sub_6c8c30(void*);
extern "C" void __fastcall sub_6c9050(void*);
extern "C" void __fastcall sub_6c9080(void*);
extern "C" void __fastcall sub_6c9220(void*, int, void*);
extern "C" void __fastcall sub_6c92e0(void*, void*, void*);

extern "C" void* (__thiscall *g_pfnCreateCompatibleBitmap)(void*, int, int);
extern "C" void* (__stdcall *g_pfnCreateRectRgnIndirect)(void*);
extern "C" void* (__stdcall *g_pfnSelectObject)(void*, void*);
extern "C" int (__stdcall *g_pfnCopyRect)(void*, void*, void*, void*);
extern "C" int (__stdcall *g_pfnInvalidateRect)(void*, void*, int);

void CXTPCommandBarAnimation::Draw(int x, int y)
{
    void* pCommandBar = m_pCommandBar;
    if (pCommandBar != 0)
    {
        sub_63022c((char*)this + 4);
        m_nState = 1;
        g_pfnInvalidateRect(*(void**)((char*)pCommandBar + 0x20), 0, 0);
        return;
    }

    if ((char*)this + 4 == 0 || m_pAnimateInfo == 0)
    {
        g_pfnInvalidateRect(*(void**)((char*)pCommandBar + 0x20), 0, 0);
        return;
    }

    if (sub_6c8c30((char*)this + 4) == 0)
    {
        g_pfnInvalidateRect(*(void**)((char*)pCommandBar + 0x20), 0, 0);
        return;
    }

    sub_630946(pCommandBar);
    sub_680000(pCommandBar);

    void* hdc = 0;
    g_pfnCreateCompatibleBitmap(0, 0, 0);

    sub_7383e2((char*)this + 0x34);
    sub_63d780((char*)this + 0x34, (char*)this + 0x44);

    void* pRgn = 0;
    sub_630238(&pRgn, 0);

    void* hBitmap = g_pfnCreateCompatibleBitmap(0, 0, 0);
    void* hOldBitmap = g_pfnSelectObject(0, hBitmap);

    void* pRect = 0;
    sub_73850e((char*)this + 0x2c, &pRect);

    void* pRect2 = 0;
    sub_73850e((char*)this + 0x2c, 0);

    sub_7383e2((char*)this + 0x5c);
    sub_63d780((char*)this + 0x5c, (char*)this + 0x44);

    void* pAnimateInfo = m_pAnimateInfo;
    void* hBitmap2 = g_pfnCreateCompatibleBitmap(0, 0, 0);
    void* hOldBitmap2 = g_pfnSelectObject(0, hBitmap2);

    if (m_nState == 0)
    {
        sub_6c9220(this, 1, &pRect);
        sub_63d7c0((char*)this + 0x7c, 0, 0, 0, 0, 0, 0, 0xcc0020);
        sub_63d7c0((char*)this + 0x64, 0, 0, 0, 0, 0, 0, 0xcc0020);
    }
    else
    {
        void* pInfo = sub_62fef6(0x38);
        if (pInfo != 0)
        {
            sub_6c9050(pInfo);
        }
        else
        {
            pInfo = 0;
        }

        *(int*)((char*)pInfo + 0x10) = 0;
        *(int*)((char*)pInfo + 0x14) = 0;
        *(int*)((char*)pInfo + 0x18) = 0;
        *(int*)((char*)pInfo + 0x1c) = 0;
        *(int*)((char*)pInfo + 0x20) = 1;

        sub_647fc0(0, 0, 0, (char*)pInfo + 4);
        *(int*)pInfo = 0;
        sub_647fc0(0, 0, 0, (char*)pInfo + 0xc);
        *(int*)((char*)pInfo + 8) = 0;

        sub_7383e2((char*)this + 0x7c);
        sub_63d780((char*)this + 0x7c, (char*)this + 0x44);
        sub_7383e2((char*)this + 0x8c);
        sub_63d780((char*)this + 0x8c, (char*)this + 0x44);

        void* hBitmap3 = g_pfnCreateCompatibleBitmap(0, 0, 0);
        void* hOldBitmap3 = g_pfnSelectObject(0, hBitmap3);

        sub_63d7c0((char*)this + 0x9c, 0, 0, 0, 0, 0, 0, 0xcc0020);
        sub_63d7c0((char*)this + 0xac, 0, 0, 0, 0, 0, 0, 0xcc0020);
        sub_63d7c0((char*)this + 0x7c, 0, 0, 0, 0, 0, 0, 0xcc0020);

        void* hBitmap4 = g_pfnCreateCompatibleBitmap(0, 0, 0);
        void* hOldBitmap4 = g_pfnSelectObject(0, hBitmap4);

        int cmp = 0;
        if (cmp == 0)
        {
            sub_6c9080(pInfo);
            sub_62fc62(pInfo);
        }
        else
        {
            sub_6c92e0((char*)this + 0x80, (char*)this + 0x48, pInfo);
        }

        sub_7383dc((char*)this + 0x8c);
        sub_7383dc((char*)this + 0x7c);
    }

    g_pfnSelectObject(0, hOldBitmap);
    g_pfnSelectObject(0, hOldBitmap2);

    sub_7383dc((char*)this + 0x5c);
    sub_41f680((char*)this + 0x2c);
    sub_41f680((char*)this + 0x24);
    sub_7383dc((char*)this + 0x34);
    sub_630940((char*)this + 0x44);
}
