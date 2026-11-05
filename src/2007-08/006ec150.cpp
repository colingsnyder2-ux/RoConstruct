// from server: 25% by colin
struct CXTPDockingPaneContextStickerWnd
{
    char pad[0x54];
    unsigned char m_nFlags;
    char pad2[3];
    int m_nState;
    char pad3[4];
    void* m_pContext;

    void Draw(int param);
};

extern "C" int __stdcall sub_006ebd20(void* p);
extern "C" void __stdcall sub_006ebfc0(CXTPDockingPaneContextStickerWnd* self, int a, int b, int c, int d);

void CXTPDockingPaneContextStickerWnd::Draw(int param)
{
    int edx;
    int ebx;
    int ebp;
    int edi;
    int eax;

    edx = 0;
    ebp = (m_nFlags & 0x20) == 0x20;

    if (sub_006ebd20(m_pContext) != 0)
    {
        ebx = param;
        edi = ebp ? 0xb : 0xa;
        if (ebp)
        {
            eax = (m_nState != 0x10) ? 1 : 0;
            eax += 9;
            eax = eax + eax * 2;
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)(0x8c9458 + eax * 8), 1);
        }
        if (m_nFlags & 4)
        {
            eax = (m_nState != 4) ? 1 : 0;
            eax = (eax - 1) & 4;
            eax += edi;
            eax = eax + eax * 2;
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)(0x8c9458 + eax * 8), ebp);
        }
        if (m_nFlags & 1)
        {
            eax = (m_nState == 1) ? 1 : 0;
            eax = eax * 4 + 1;
            eax += edi;
            eax = eax + eax * 2;
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)(0x8c9458 + eax * 8), ebp);
        }
        if (m_nFlags & 8)
        {
            eax = (m_nState == 8) ? 1 : 0;
            eax = eax * 4 + 2;
            eax += edi;
            eax = eax + eax * 2;
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)(0x8c9458 + eax * 8), ebp);
        }
        if (m_nFlags & 2)
        {
            eax = (m_nState == 2) ? 1 : 0;
            eax = eax * 4 + 3;
            eax += edi;
            eax = eax + eax * 2;
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)(0x8c9458 + eax * 8), ebp);
        }
        if (m_nFlags & 0x10)
        {
            sub_006ebfc0(this, ebx, 0x24ef, *(int*)0x8c9518, 1);
        }
        return;
    }

    edx = 2;
    if (edx == 2)
    {
        ebx = 0x24ed;
    }
    else
    {
        ebx = (edx == 3) ? 1 : 0;
        ebx = ebx + ebx + 0x24ec;
    }

    edi = param;

    if (ebp)
    {
        sub_006ebfc0(this, edi, 0x24eb, *(int*)0x8c9440, 1);
    }

    if (m_nFlags & 4)
    {
        eax = (m_nState != 4) ? 1 : 0;
        eax = (eax - 1) & 4;
        eax = eax + eax * 2;
        sub_006ebfc0(this, edi, ebx, *(int*)(0x8c9350 + eax * 8), ebp);
    }
    if (m_nFlags & 1)
    {
        eax = (m_nState == 1) ? 1 : 0;
        eax = eax * 4 + 1;
        eax = eax + eax * 2;
        sub_006ebfc0(this, edi, ebx, *(int*)(0x8c9350 + eax * 8), ebp);
    }
    if (m_nFlags & 8)
    {
        eax = (m_nState == 8) ? 1 : 0;
        eax = eax * 4 + 2;
        eax = eax + eax * 2;
        sub_006ebfc0(this, edi, ebx, *(int*)(0x8c9350 + eax * 8), ebp);
    }
    if (m_nFlags & 2)
    {
        eax = (m_nState == 2) ? 1 : 0;
        eax = eax * 4 + 3;
        eax = eax + eax * 2;
        sub_006ebfc0(this, edi, ebx, *(int*)(0x8c9350 + eax * 8), ebp);
    }
    if (m_nFlags & 0x10)
    {
        eax = (m_nState == 0x10) ? 1 : 0;
        eax += 8;
        eax = eax + eax * 2;
        sub_006ebfc0(this, edi, ebx, *(int*)(0x8c9350 + eax * 8), 1);
    }
}
