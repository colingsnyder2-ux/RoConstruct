// from server: 100% by EspClaude
// from server: 67% by colin
// roc 2007-08 00711ca0  unit: CXTColorSelectorCtrl  size: 496 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00711ca0
//
// 00711ca0  6aff                 push -1
// 00711ca2  6869a77600           push 0x76a769
// 00711ca7  64a100000000         mov eax, dword ptr fs:[0]
// 00711cad  50                   push eax
// 00711cae  53                   push ebx
// 00711caf  56                   push esi
// 00711cb0  57                   push edi
// 00711cb1  a188518b00           mov eax, dword ptr [0x8b5188]
// 00711cb6  33c4                 xor eax, esp
// 00711cb8  50                   push eax
// 00711cb9  8d442410             lea eax, [esp + 0x10]
// 00711cbd  64a300000000         mov dword ptr fs:[0], eax
// 00711cc3  8bf1                 mov esi, ecx
// 00711cc5  8b442430             mov eax, dword ptr [esp + 0x30]
// 00711cc9  85c0                 test eax, eax
// 00711ccb  898680000000         mov dword ptr [esi + 0x80], eax
// 00711cd1  0f8457010000         je 0x711e2e
// 00711cd7  8b4020               mov eax, dword ptr [eax + 0x20]
// 00711cda  50                   push eax
// 00711cdb  e840c0f8ff           call 0x69dd20
// 00711ce0  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00711ce4  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00711ce8  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00711cec  8d442420             lea eax, [esp + 0x20]
// 00711cf0  50                   push eax
// 00711cf1  8d9e8c000000         lea ebx, [esi + 0x8c]
// 00711cf7  53                   push ebx
// 00711cf8  89beac000000         mov dword ptr [esi + 0xac], edi
// 00711cfe  898eb8000000         mov dword ptr [esi + 0xb8], ecx
// 00711d04  8996bc000000         mov dword ptr [esi + 0xbc], edx
// 00711d0a  ff15e0ed7700         call dword ptr [0x77ede0]
// 00711d10  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 00711d16  038e9c000000         add ecx, dword ptr [esi + 0x9c]
// 00711d1c  8b13                 mov edx, dword ptr [ebx]
// 00711d1e  8d841190000000       lea eax, [ecx + edx + 0x90]
// 00711d25  8b8ea8000000         mov ecx, dword ptr [esi + 0xa8]
// 00711d2b  038ea0000000         add ecx, dword ptr [esi + 0xa0]
// 00711d31  f686ac00000002       test byte ptr [esi + 0xac], 2
// 00711d38  898694000000         mov dword ptr [esi + 0x94], eax
// 00711d3e  8b8698000000         mov eax, dword ptr [esi + 0x98]
// 00711d44  898690000000         mov dword ptr [esi + 0x90], eax
// 00711d4a  8d44016e             lea eax, [ecx + eax + 0x6e]
// 00711d4e  898698000000         mov dword ptr [esi + 0x98], eax
// 00711d54  7412                 je 0x711d68
// 00711d56  83c022               add eax, 0x22
// 00711d59  c7467428000000       mov dword ptr [esi + 0x74], 0x28
// 00711d60  898698000000         mov dword ptr [esi + 0x98], eax
// 00711d66  eb07                 jmp 0x711d6f
// 00711d68  c7467410000000       mov dword ptr [esi + 0x74], 0x10
// 00711d6f  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00711d72  8bc1                 mov eax, ecx
// 00711d74  99                   cdq 
// 00711d75  f77e70               idiv dword ptr [esi + 0x70]
// 00711d78  83c101               add ecx, 1
// 00711d7b  894e74               mov dword ptr [esi + 0x74], ecx
// 00711d7e  89466c               mov dword ptr [esi + 0x6c], eax
// 00711d81  e87ce1f1ff           call 0x62ff02
// 00711d86  68007f0000           push 0x7f00
// 00711d8b  6a00                 push 0
// 00711d8d  ff1520ec7700         call dword ptr [0x77ec20]
// 00711d93  6a00                 push 0
// 00711d95  6a00                 push 0
// 00711d97  50                   push eax
// 00711d98  6a00                 push 0
// 00711d9a  e857e7f1ff           call 0x6304f6
// 00711d9f  50                   push eax
// 00711da0  8d4c2434             lea ecx, [esp + 0x34]
// 00711da4  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00711daa  f686ac00000004       test byte ptr [esi + 0xac], 4
// 00711db1  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00711db9  7509                 jne 0x711dc4
// 00711dbb  838698000000e4       add dword ptr [esi + 0x98], -0x1c
// 00711dc2  eb20                 jmp 0x711de4
// 00711dc4  833dac978c0000       cmp dword ptr [0x8c97ac], 0
// 00711dcb  7e17                 jle 0x711de4
// 00711dcd  8b9688000000         mov edx, dword ptr [esi + 0x88]
// 00711dd3  83c204               add edx, 4
// 00711dd6  019698000000         add dword ptr [esi + 0x98], edx
// 00711ddc  a1ac978c00           mov eax, dword ptr [0x8c97ac]
// 00711de1  014674               add dword ptr [esi + 0x74], eax
// 00711de4  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 00711dea  6a00                 push 0
// 00711dec  81e700000080         and edi, 0x80000000
// 00711df2  6a00                 push 0
// 00711df4  f7df                 neg edi
// 00711df6  51                   push ecx
// 00711df7  1bff                 sbb edi, edi
// 00711df9  53                   push ebx
// 00711dfa  81e700000040         and edi, 0x40000000
// 00711e00  81c700000040         add edi, 0x40000000
// 00711e06  57                   push edi
// 00711e07  6854597800           push 0x785954
// 00711e0c  8d4c2448             lea ecx, [esp + 0x48]
// 00711e10  ff1598dd7700         call dword ptr [0x77dd98]
// 00711e16  50                   push eax
// 00711e17  6a00                 push 0
// 00711e19  8bce                 mov ecx, esi
// 00711e1b  e8c0def1ff           call 0x62fce0
// 00711e20  85c0                 test eax, eax
// 00711e22  7521                 jne 0x711e45
// 00711e24  8d4c2430             lea ecx, [esp + 0x30]
// 00711e28  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00711e2e  33c0                 xor eax, eax
// 00711e30  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00711e34  64890d00000000       mov dword ptr fs:[0], ecx
// 00711e3b  59                   pop ecx
// 00711e3c  5f                   pop edi
// 00711e3d  5e                   pop esi
// 00711e3e  5b                   pop ebx
// 00711e3f  83c40c               add esp, 0xc
// 00711e42  c22000               ret 0x20
// 00711e45  6a08                 push 8
// 00711e47  8bce                 mov ecx, esi
// 00711e49  e8fce0f1ff           call 0x62ff4a
// 00711e4e  e89d5af8ff           call 0x6978f0
// 00711e53  05dc000000           add eax, 0xdc
// 00711e58  7403                 je 0x711e5d
// 00711e5a  8b4004               mov eax, dword ptr [eax + 4]
// 00711e5d  8b5620               mov edx, dword ptr [esi + 0x20]
// 00711e60  6a01                 push 1
// 00711e62  50                   push eax
// 00711e63  6a30                 push 0x30
// 00711e65  52                   push edx
// 00711e66  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00711e6c  8d4c2430             lea ecx, [esp + 0x30]
// 00711e70  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00711e76  b801000000           mov eax, 1
// 00711e7b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00711e7f  64890d00000000       mov dword ptr fs:[0], ecx
// 00711e86  59                   pop ecx
// 00711e87  5f                   pop edi
// 00711e88  5e                   pop esi
// 00711e89  5b                   pop ebx
// 00711e8a  83c40c               add esp, 0xc
// 00711e8d  c22000               ret 0x20

typedef void* HWND;
typedef void* HCURSOR;
typedef unsigned long DWORD;

struct tagRECT { long left, top, right, bottom; };
struct CRect : tagRECT {};

extern "C" __declspec(dllimport) int __stdcall CopyRect(tagRECT*, const tagRECT*);
extern "C" __declspec(dllimport) HCURSOR __stdcall LoadCursorA(void*, const char*);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(HWND, unsigned int, unsigned int, long);

struct CString {
    void* m_p;
    __declspec(dllimport) CString(const char*);
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) operator const char*() const;
};

const char* __stdcall AfxRegisterWndClass(unsigned int, HCURSOR, void*, void*);

struct CGdiObject {
    void* vtbl;
    void* m_hObject;
    operator void*() const { void* h = (void*)this; if (h != 0) h = m_hObject; return h; }
};

struct AuxData {
    char pad[0xdc];
    CGdiObject font;
};
AuxData& XTAuxData();

struct CWnd {
    char pad0[0x20];
    HWND m_hWnd;
};

void __stdcall NotifyParent(HWND);
void PrepareModuleState();

extern int g_nExtraRows;
extern const char g_szWindowName[];

struct CXTColorSelectorCtrl : CWnd
{
    char pad24[0x6c - 0x24];
    int m_6c;
    int m_70;
    int m_74;
    char pad78[0x80 - 0x78];
    CWnd* m_pParent;
    char pad84[0x88 - 0x84];
    int m_88;
    CRect m_rcWnd;
    CRect m_rcBorders;
    DWORD m_dwPopup;
    char padb0[0xb8 - 0xb0];
    int m_b8;
    int m_bc;

    int CreateEx(DWORD dwExStyle, const char* lpszClassName, const char* lpszWindowName, DWORD dwStyle,
                 const tagRECT& rect, CWnd* pParentWnd, unsigned int nID, void* lpParam);
    void SetSelection(int);
    int Create(CRect rect, CWnd* pParentWnd, DWORD dwPopup, int p7, int p8);
};

int CXTColorSelectorCtrl::Create(CRect rect, CWnd* pParentWnd, DWORD dwPopup, int p7, int p8)
{
    m_pParent = pParentWnd;
    if (pParentWnd == 0)
        return 0;

    NotifyParent(pParentWnd->m_hWnd);

    m_dwPopup = dwPopup;
    m_b8 = p7;
    m_bc = p8;

    CopyRect(&m_rcWnd, &rect);

    m_rcWnd.right = m_rcWnd.left + 0x90 + m_rcBorders.left + m_rcBorders.right;
    m_rcWnd.top = m_rcWnd.bottom;
    m_rcWnd.bottom = m_rcWnd.top + 0x6e + m_rcBorders.top + m_rcBorders.bottom;

    if ((m_dwPopup & 2) != 0)
    {
        m_74 = 0x28;
        m_rcWnd.bottom += 0x22;
    }
    else
    {
        m_74 = 0x10;
    }

    m_6c = m_74 / m_70;
    m_74++;

    PrepareModuleState();

    HCURSOR hCursor = LoadCursorA(0, (const char*)0x7f00);
    CString strClass(AfxRegisterWndClass(0, hCursor, 0, 0));

    if ((m_dwPopup & 4) == 0)
    {
        m_rcWnd.bottom -= 0x1c;
    }
    else if (g_nExtraRows > 0)
    {
        m_rcWnd.bottom += m_88 + 4;
        m_74 += g_nExtraRows;
    }

    if (!CreateEx(0, strClass, g_szWindowName, (dwPopup & 0x80000000) ? 0x80000000 : 0x40000000,
                  m_rcWnd, m_pParent, 0, 0))
        return 0;

    SetSelection(8);

    SendMessageA(m_hWnd, 0x30, (unsigned int)(void*)XTAuxData().font, 1);
    return 1;
}
