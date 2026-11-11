// from server: 100% by EspClaude
// from server: 83% by colin
// roc 2007-08 00433ec0  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433ec0
// 00433ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00433ec4  56                   push esi
// 00433ec5  50                   push eax
// 00433ec6  8bf1                 mov esi, ecx
// 00433ec8  e8fbc61f00           call 0x6305c8
// 00433ecd  83f8ff               cmp eax, -1
// 00433ed0  7506                 jne 0x433ed8
// 00433ed2  0bc0                 or eax, eax
// 00433ed4  5e                   pop esi
// 00433ed5  c20400               ret 4
// 00433ed8  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00433edb  57                   push edi
// 00433edc  51                   push ecx
// 00433edd  ff15b4ed7700         call dword ptr [0x77edb4]
// 00433ee3  50                   push eax
// 00433ee4  e80fc41f00           call 0x6302f8
// 00433ee9  8bf8                 mov edi, eax
// 00433eeb  85ff                 test edi, edi
// 00433eed  7421                 je 0x433f10
// 00433eef  8b5704               mov edx, dword ptr [edi + 4]
// 00433ef2  52                   push edx
// 00433ef3  ff15aced7700         call dword ptr [0x77edac]
// 00433ef9  85c0                 test eax, eax
// 00433efb  7413                 je 0x433f10
// 00433efd  8bcf                 mov ecx, edi
// 00433eff  e868c51f00           call 0x63046c
// 00433f04  8b4620               mov eax, dword ptr [esi + 0x20]
// 00433f07  6a00                 push 0
// 00433f09  50                   push eax
// 00433f0a  ff15b0ed7700         call dword ptr [0x77edb0]
// 00433f10  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00433f13  6a01                 push 1
// 00433f15  6800e90000           push 0xe900
// 00433f1a  51                   push ecx
// 00433f1b  e8dec31f00           call 0x6302fe
// 00433f20  6a20                 push 0x20
// 00433f22  8bf0                 mov esi, eax
// 00433f24  6a00                 push 0
// 00433f26  6800008000           push 0x800000
// 00433f2b  8bce                 mov ecx, esi
// 00433f2d  e886c41f00           call 0x6303b8
// 00433f32  6a20                 push 0x20
// 00433f34  6a00                 push 0
// 00433f36  6800020000           push 0x200
// 00433f3b  8bce                 mov ecx, esi
// 00433f3d  e8d2c21f00           call 0x630214
// 00433f42  5f                   pop edi
// 00433f43  33c0                 xor eax, eax
// 00433f45  5e                   pop esi
// 00433f46  c20400               ret 4

struct HWND__; typedef HWND__* HWND;
struct HMENU__; typedef HMENU__* HMENU;
struct CREATESTRUCTA;

extern "C" __declspec(dllimport) HMENU __stdcall GetMenu(HWND);
extern "C" __declspec(dllimport) int __stdcall IsMenu(HMENU);
extern "C" __declspec(dllimport) int __stdcall SetMenu(HWND, HMENU);

struct CMenu {
    void* vfptr_pad;
    HMENU m_hMenu;
    static CMenu* __stdcall FromHandle(HMENU);
    int DestroyMenu();
};

struct CWnd {
    char pad[0x20];
    HWND m_hWnd;
    static CWnd* __stdcall GetDescendantWindow(HWND hWnd, unsigned int nID, int bOnlyPerm);
    int ModifyStyle(unsigned long dwRemove, unsigned long dwAdd, unsigned int nFlags);
    int ModifyStyleEx(unsigned long dwRemove, unsigned long dwAdd, unsigned int nFlags);
};

struct CFrameWnd : CWnd {
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
};

struct VCFrameWnd : CFrameWnd {
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
};

int VCFrameWnd::OnCreate(CREATESTRUCTA* lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    CMenu* pMenu = CMenu::FromHandle(::GetMenu(m_hWnd));
    if (pMenu && ::IsMenu(pMenu->m_hMenu))
    {
        pMenu->DestroyMenu();
        ::SetMenu(m_hWnd, 0);
    }

    CWnd* pWnd = CWnd::GetDescendantWindow(m_hWnd, 0xe900, 1);
    pWnd->ModifyStyle(0x800000, 0, 0x20);
    pWnd->ModifyStyleEx(0x200, 0, 0x20);
    return 0;
}
