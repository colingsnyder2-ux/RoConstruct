// from server: 100% by EspClaude
// from server: 63% by colin
// roc 2008-06 004592b0  unit: CRobloxView  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004592b0
//
// 004592b0  83ec1c               sub esp, 0x1c
// 004592b3  53                   push ebx
// 004592b4  55                   push ebp
// 004592b5  56                   push esi
// 004592b6  57                   push edi
// 004592b7  8bf1                 mov esi, ecx
// 004592b9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004592bc  8d44241c             lea eax, [esp + 0x1c]
// 004592c0  50                   push eax
// 004592c1  51                   push ecx
// 004592c2  ff15842d8000         call dword ptr [0x802d84]
// 004592c8  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004592cc  2b7c2420             sub edi, dword ptr [esp + 0x20]
// 004592d0  8b442424             mov eax, dword ptr [esp + 0x24]
// 004592d4  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 004592d8  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 004592de  33db                 xor ebx, ebx
// 004592e0  8bd7                 mov edx, edi
// 004592e2  89442414             mov dword ptr [esp + 0x14], eax
// 004592e6  89542410             mov dword ptr [esp + 0x10], edx
// 004592ea  3bcb                 cmp ecx, ebx
// 004592ec  740e                 je 0x4592fc
// 004592ee  395920               cmp dword ptr [ecx + 0x20], ebx
// 004592f1  7409                 je 0x4592fc
// 004592f3  2de1000000           sub eax, 0xe1
// 004592f8  89442414             mov dword ptr [esp + 0x14], eax
// 004592fc  399ea0010000         cmp dword ptr [esi + 0x1a0], ebx
// 00459302  7407                 je 0x45930b
// 00459304  8d57ec               lea edx, [edi - 0x14]
// 00459307  89542410             mov dword ptr [esp + 0x10], edx
// 0045930b  3bd3                 cmp edx, ebx
// 0045930d  895c2418             mov dword ptr [esp + 0x18], ebx
// 00459311  8d4c2418             lea ecx, [esp + 0x18]
// 00459315  7c04                 jl 0x45931b
// 00459317  8d4c2410             lea ecx, [esp + 0x10]
// 0045931b  8b29                 mov ebp, dword ptr [ecx]
// 0045931d  3bc3                 cmp eax, ebx
// 0045931f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00459323  8d442418             lea eax, [esp + 0x18]
// 00459327  7c04                 jl 0x45932d
// 00459329  8d442414             lea eax, [esp + 0x14]
// 0045932d  83bed000000000       cmp dword ptr [esi + 0xd0], 0
// 00459334  8b18                 mov ebx, dword ptr [eax]
// 00459336  7413                 je 0x45934b
// 00459338  6a01                 push 1
// 0045933a  55                   push ebp
// 0045933b  53                   push ebx
// 0045933c  6a00                 push 0
// 0045933e  6a00                 push 0
// 00459340  8d8eb0000000         lea ecx, [esi + 0xb0]
// 00459346  e801772400           call 0x6a0a4c
// 0045934b  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 00459351  85c9                 test ecx, ecx
// 00459353  7416                 je 0x45936b
// 00459355  83792000             cmp dword ptr [ecx + 0x20], 0
// 00459359  7410                 je 0x45936b
// 0045935b  6a01                 push 1
// 0045935d  57                   push edi
// 0045935e  68e1000000           push 0xe1
// 00459363  6a00                 push 0
// 00459365  53                   push ebx
// 00459366  e8e1762400           call 0x6a0a4c
// 0045936b  83bea001000000       cmp dword ptr [esi + 0x1a0], 0
// 00459372  7413                 je 0x459387
// 00459374  6a01                 push 1
// 00459376  6a14                 push 0x14
// 00459378  53                   push ebx
// 00459379  55                   push ebp
// 0045937a  6a00                 push 0
// 0045937c  8d8e80010000         lea ecx, [esi + 0x180]
// 00459382  e8c5762400           call 0x6a0a4c
// 00459387  5f                   pop edi
// 00459388  5e                   pop esi
// 00459389  5d                   pop ebp
// 0045938a  5b                   pop ebx
// 0045938b  83c41c               add esp, 0x1c
// 0045938e  c3                   ret 

// from server: 62% by colin
// roc 2008-06 004592b0  unit: CRobloxView  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004592b0
//
// 004592b0  83ec1c               sub esp, 0x1c
// 004592b3  53                   push ebx
// 004592b4  55                   push ebp
// 004592b5  56                   push esi
// 004592b6  57                   push edi
// 004592b7  8bf1                 mov esi, ecx
// 004592b9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004592bc  8d44241c             lea eax, [esp + 0x1c]
// 004592c0  50                   push eax
// 004592c1  51                   push ecx
// 004592c2  ff15842d8000         call dword ptr [0x802d84]
// 004592c8  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004592cc  2b7c2420             sub edi, dword ptr [esp + 0x20]
// 004592d0  8b442424             mov eax, dword ptr [esp + 0x24]
// 004592d4  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 004592d8  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 004592de  33db                 xor ebx, ebx
// 004592e0  8bd7                 mov edx, edi
// 004592e2  89442414             mov dword ptr [esp + 0x14], eax
// 004592e6  89542410             mov dword ptr [esp + 0x10], edx
// 004592ea  3bcb                 cmp ecx, ebx
// 004592ec  740e                 je 0x4592fc
// 004592ee  395920               cmp dword ptr [ecx + 0x20], ebx
// 004592f1  7409                 je 0x4592fc
// 004592f3  2de1000000           sub eax, 0xe1
// 004592f8  89442414             mov dword ptr [esp + 0x14], eax
// 004592fc  399ea0010000         cmp dword ptr [esi + 0x1a0], ebx
// 00459302  7407                 je 0x45930b
// 00459304  8d57ec               lea edx, [edi - 0x14]
// 00459307  89542410             mov dword ptr [esp + 0x10], edx
// 0045930b  3bd3                 cmp edx, ebx
// 0045930d  895c2418             mov dword ptr [esp + 0x18], ebx
// 00459311  8d4c2418             lea ecx, [esp + 0x18]
// 00459315  7c04                 jl 0x45931b
// 00459317  8d4c2410             lea ecx, [esp + 0x10]
// 0045931b  8b29                 mov ebp, dword ptr [ecx]
// 0045931d  3bc3                 cmp eax, ebx
// 0045931f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00459323  8d442418             lea eax, [esp + 0x18]
// 00459327  7c04                 jl 0x45932d
// 00459329  8d442414             lea eax, [esp + 0x14]
// 0045932d  83bed000000000       cmp dword ptr [esi + 0xd0], 0
// 00459334  8b18                 mov ebx, dword ptr [eax]
// 00459336  7413                 je 0x45934b
// 00459338  6a01                 push 1
// 0045933a  55                   push ebp
// 0045933b  53                   push ebx
// 0045933c  6a00                 push 0
// 0045933e  6a00                 push 0
// 00459340  8d8eb0000000         lea ecx, [esi + 0xb0]
// 00459346  e801772400           call 0x6a0a4c
// 0045934b  8b8ed8010000         mov ecx, dword ptr [esi + 0x1d8]
// 00459351  85c9                 test ecx, ecx
// 00459353  7416                 je 0x45936b
// 00459355  83792000             cmp dword ptr [ecx + 0x20], 0
// 00459359  7410                 je 0x45936b
// 0045935b  6a01                 push 1
// 0045935d  57                   push edi
// 0045935e  68e1000000           push 0xe1
// 00459363  6a00                 push 0
// 00459365  53                   push ebx
// 00459366  e8e1762400           call 0x6a0a4c
// 0045936b  83bea001000000       cmp dword ptr [esi + 0x1a0], 0
// 00459372  7413                 je 0x459387
// 00459374  6a01                 push 1
// 00459376  6a14                 push 0x14
// 00459378  53                   push ebx
// 00459379  55                   push ebp
// 0045937a  6a00                 push 0
// 0045937c  8d8e80010000         lea ecx, [esi + 0x180]
// 00459382  e8c5762400           call 0x6a0a4c
// 00459387  5f                   pop edi
// 00459388  5e                   pop esi
// 00459389  5d                   pop ebp
// 0045938a  5b                   pop ebx
// 0045938b  83c41c               add esp, 0x1c
// 0045938e  c3                   ret 
#include <algorithm>

struct RECT { long left, top, right, bottom; };
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void *, RECT *);

struct CRect : RECT {
    int Width() const { return right - left; }
    int Height() const { return bottom - top; }
};

struct CWnd {
    char pad[0x20];
    void *m_hWnd;
    void MoveWindow(int x, int y, int nWidth, int nHeight, int bRepaint = 1);
    void GetClientRect(RECT *r) const { ::GetClientRect(m_hWnd, r); }
};

struct CRobloxView : CWnd {
    char pad24[0xb0 - 0x24];
    CWnd viewPane;
    char pad_d4[0x180 - 0xd4];
    CWnd statusPane;
    char pad_1a4[0x1d8 - 0x1a4];
    CWnd *sidePane;
    void OnSize();
};

void CRobloxView::OnSize()
{
    CRect rect;
    GetClientRect(&rect);
    int height = rect.Height();
    int width = rect.Width();
    int viewHeight = height;

    if (sidePane && sidePane->m_hWnd)
        width -= 0xe1;
    if (statusPane.m_hWnd)
        viewHeight = height - 0x14;

    int h = std::max(viewHeight, 0);
    int w = std::max(width, 0);

    if (viewPane.m_hWnd)
        viewPane.MoveWindow(0, 0, w, h, 1);
    if (sidePane && sidePane->m_hWnd)
        sidePane->MoveWindow(w, 0, 0xe1, height, 1);
    if (statusPane.m_hWnd)
        statusPane.MoveWindow(0, h, w, 0x14, 1);
}
