// from server: 100% by EspClaude
// from server: 67% by colin
// roc 2007-08 0044bbd0  unit: CRobloxControlColorSelector  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044bbd0
//
// 0044bbd0  83ec18               sub esp, 0x18
// 0044bbd3  a1bcbe8b00           mov eax, dword ptr [0x8bbebc]
// 0044bbd8  53                   push ebx
// 0044bbd9  55                   push ebp
// 0044bbda  56                   push esi
// 0044bbdb  33f6                 xor esi, esi
// 0044bbdd  3bc6                 cmp eax, esi
// 0044bbdf  57                   push edi
// 0044bbe0  894c2414             mov dword ptr [esp + 0x14], ecx
// 0044bbe4  7506                 jne 0x44bbec
// 0044bbe6  89742410             mov dword ptr [esp + 0x10], esi
// 0044bbea  eb1c                 jmp 0x44bc08
// 0044bbec  8b15c0be8b00         mov edx, dword ptr [0x8bbec0]
// 0044bbf2  2bd0                 sub edx, eax
// 0044bbf4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044bbf9  f7ea                 imul edx
// 0044bbfb  d1fa                 sar edx, 1
// 0044bbfd  8bc2                 mov eax, edx
// 0044bbff  c1e81f               shr eax, 0x1f
// 0044bc02  03c2                 add eax, edx
// 0044bc04  89442410             mov dword ptr [esp + 0x10], eax
// 0044bc08  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0044bc0c  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0044bc10  53                   push ebx
// 0044bc11  8db9c0000000         lea edi, [ecx + 0xc0]
// 0044bc17  55                   push ebp
// 0044bc18  57                   push edi
// 0044bc19  ff1594ed7700         call dword ptr [0x77ed94]
// 0044bc1f  85c0                 test eax, eax
// 0044bc21  7470                 je 0x44bc93
// 0044bc23  39742410             cmp dword ptr [esp + 0x10], esi
// 0044bc27  7e6a                 jle 0x44bc93
// 0044bc29  8da42400000000       lea esp, [esp]
// 0044bc30  8bc6                 mov eax, esi
// 0044bc32  2507000080           and eax, 0x80000007
// 0044bc37  7905                 jns 0x44bc3e
// 0044bc39  48                   dec eax
// 0044bc3a  83c8f8               or eax, 0xfffffff8
// 0044bc3d  40                   inc eax
// 0044bc3e  8b0f                 mov ecx, dword ptr [edi]
// 0044bc40  c1e005               shl eax, 5
// 0044bc43  8d4c0802             lea ecx, [eax + ecx + 2]
// 0044bc47  8bc6                 mov eax, esi
// 0044bc49  99                   cdq 
// 0044bc4a  83e207               and edx, 7
// 0044bc4d  03c2                 add eax, edx
// 0044bc4f  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044bc53  8b92c4000000         mov edx, dword ptr [edx + 0xc4]
// 0044bc59  c1f803               sar eax, 3
// 0044bc5c  c1e005               shl eax, 5
// 0044bc5f  8d441002             lea eax, [eax + edx + 2]
// 0044bc63  8944241c             mov dword ptr [esp + 0x1c], eax
// 0044bc67  83c020               add eax, 0x20
// 0044bc6a  53                   push ebx
// 0044bc6b  89442428             mov dword ptr [esp + 0x28], eax
// 0044bc6f  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0044bc73  55                   push ebp
// 0044bc74  8d442420             lea eax, [esp + 0x20]
// 0044bc78  83c120               add ecx, 0x20
// 0044bc7b  50                   push eax
// 0044bc7c  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0044bc80  ff1594ed7700         call dword ptr [0x77ed94]
// 0044bc86  85c0                 test eax, eax
// 0044bc88  7516                 jne 0x44bca0
// 0044bc8a  83c601               add esi, 1
// 0044bc8d  3b742410             cmp esi, dword ptr [esp + 0x10]
// 0044bc91  7c9d                 jl 0x44bc30
// 0044bc93  5f                   pop edi
// 0044bc94  5e                   pop esi
// 0044bc95  5d                   pop ebp
// 0044bc96  83c8ff               or eax, 0xffffffff
// 0044bc99  5b                   pop ebx
// 0044bc9a  83c418               add esp, 0x18
// 0044bc9d  c20800               ret 8
// 0044bca0  5f                   pop edi

struct RECT { long left, top, right, bottom; };
struct POINT { long x, y; };
extern "C" __declspec(dllimport) int __stdcall PtInRect(const RECT *lprc, POINT pt);

// Global table of 12-byte entries (count = (end - begin) / 12, VS2005 size()).
struct ColorEntry { int a, b, c; };
struct ColorTable {
    ColorEntry *_Myfirst;
    ColorEntry *_Mylast;
    int size() const { return _Myfirst == 0 ? 0 : (int)(_Mylast - _Myfirst); }
};
extern ColorTable g_colors;

struct CRobloxControlColorSelector {
    char pad[0xc0];
    RECT m_rect;
    int HitTest(POINT pt);
};

int CRobloxControlColorSelector::HitTest(POINT pt)
{
    int count = g_colors.size();
    if (PtInRect(&m_rect, pt)) {
        for (int i = 0; i < count; i++) {
            RECT rc;
            rc.left = (i % 8) * 32 + m_rect.left + 2;
            rc.top = (i / 8) * 32 + m_rect.top + 2;
            rc.right = rc.left + 32;
            rc.bottom = rc.top + 32;
            if (PtInRect(&rc, pt))
                return i;
        }
    }
    return -1;
}
