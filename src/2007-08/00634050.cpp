// from server: 97% by EspClaude
// from server: 67% by colin
// roc 2007-08 00634050  unit: CXTPCommandBar  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00634050
//
// 00634050  8b442404             mov eax, dword ptr [esp + 4]
// 00634054  83ec08               sub esp, 8
// 00634057  3d63030000           cmp eax, 0x363
// 0063405c  53                   push ebx
// 0063405d  56                   push esi
// 0063405e  57                   push edi
// 0063405f  8bf1                 mov esi, ecx
// 00634061  7547                 jne 0x6340aa
// 00634063  33ff                 xor edi, edi
// 00634065  39be84000000         cmp dword ptr [esi + 0x84], edi
// 0063406b  0f8ed5010000         jle 0x634246
// 00634071  8d5f04               lea ebx, [edi + 4]
// 00634074  57                   push edi
// 00634075  8bce                 mov ecx, esi
// 00634077  e894e8ffff           call 0x632910
// 0063407c  3998fc000000         cmp dword ptr [eax + 0xfc], ebx
// 00634082  7510                 jne 0x634094
// 00634084  8b10                 mov edx, dword ptr [eax]
// 00634086  6a01                 push 1
// 00634088  8bc8                 mov ecx, eax
// 0063408a  8b82e0010000         mov eax, dword ptr [edx + 0x1e0]
// 00634090  6a01                 push 1
// 00634092  ffd0                 call eax
// 00634094  83c701               add edi, 1
// 00634097  3bbe84000000         cmp edi, dword ptr [esi + 0x84]
// 0063409d  7cd5                 jl 0x634074
// 0063409f  5f                   pop edi
// 006340a0  5e                   pop esi
// 006340a1  33c0                 xor eax, eax
// 006340a3  5b                   pop ebx
// 006340a4  83c408               add esp, 8
// 006340a7  c21000               ret 0x10
// 006340aa  83f815               cmp eax, 0x15
// 006340ad  7558                 jne 0x634107
// 006340af  e8bc4e0300           call 0x668f70
// 006340b4  8bc8                 mov ecx, eax
// 006340b6  e8a5600300           call 0x66a160
// 006340bb  8bce                 mov ecx, esi
// 006340bd  e80ee1ffff           call 0x6321d0
// 006340c2  8b10                 mov edx, dword ptr [eax]
// 006340c4  8bc8                 mov ecx, eax
// 006340c6  8b82a8000000         mov eax, dword ptr [edx + 0xa8]
// 006340cc  ffd0                 call eax
// 006340ce  8bce                 mov ecx, esi
// 006340d0  e81be1ffff           call 0x6321f0
// 006340d5  8bc8                 mov ecx, eax
// 006340d7  e824870100           call 0x64c800
// 006340dc  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 006340e2  8b5120               mov edx, dword ptr [ecx + 0x20]
// 006340e5  6805010000           push 0x105
// 006340ea  6a00                 push 0
// 006340ec  6a00                 push 0
// 006340ee  52                   push edx
// 006340ef  ff151cee7700         call dword ptr [0x77ee1c]
// 006340f5  8bce                 mov ecx, esi
// 006340f7  e8a4f2ffff           call 0x6333a0
// 006340fc  5f                   pop edi
// 006340fd  5e                   pop esi
// 006340fe  33c0                 xor eax, eax
// 00634100  5b                   pop ebx
// 00634101  83c408               add esp, 8
// 00634104  c21000               ret 0x10
// 00634107  83f81a               cmp eax, 0x1a
// 0063410a  7513                 jne 0x63411f
// 0063410c  e8bfe0ffff           call 0x6321d0
// 00634111  8b10                 mov edx, dword ptr [eax]
// 00634113  8bc8                 mov ecx, eax
// 00634115  8b82a8000000         mov eax, dword ptr [edx + 0xa8]
// 0063411b  ffd0                 call eax
// 0063411d  ebbd                 jmp 0x6340dc
// 0063411f  83f810               cmp eax, 0x10
// 00634122  751b                 jne 0x63413f
// 00634124  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00634127  83781400             cmp dword ptr [eax + 0x14], 0
// 0063412b  0f8415010000         je 0x634246
// 00634131  5f                   pop edi
// 00634132  5e                   pop esi
// 00634133  b801000000           mov eax, 1
// 00634138  5b                   pop ebx
// 00634139  83c408               add esp, 8
// 0063413c  c21000               ret 0x10
// 0063413f  3d11010000           cmp eax, 0x111
// 00634144  0f85ca000000         jne 0x634214
// 0063414a  ff15d4ec7700         call dword ptr [0x77ecd4]
// 00634150  50                   push eax
// 00634151  e86ac0ffff           call 0x6301c0
// 00634156  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0063415a  8bf8                 mov edi, eax
// 0063415c  85ff                 test edi, edi
// 0063415e  7443                 je 0x6341a3
// 00634160  e8fb180000           call 0x635a60
// 00634165  50                   push eax
// 00634166  8bcf                 mov ecx, edi
// 00634168  e883c0ffff           call 0x6301f0
// 0063416d  85c0                 test eax, eax
// 0063416f  7432                 je 0x6341a3
// 00634171  8b442420             mov eax, dword ptr [esp + 0x20]
// 00634175  8b17                 mov edx, dword ptr [edi]
// 00634177  8b92f0000000         mov edx, dword ptr [edx + 0xf0]
// 0063417d  50                   push eax
// 0063417e  53                   push ebx
// 0063417f  8bcf                 mov ecx, edi
// 00634181  ffd2                 call edx
// 00634183  85c0                 test eax, eax
// 00634185  741c                 je 0x6341a3
// 00634187  8b442424             mov eax, dword ptr [esp + 0x24]
// 0063418b  85c0                 test eax, eax
// 0063418d  7406                 je 0x634195
// 0063418f  c70001000000         mov dword ptr [eax], 1
// 00634195  5f                   pop edi
// 00634196  5e                   pop esi
// 00634197  b801000000           mov eax, 1
// 0063419c  5b                   pop ebx
// 0063419d  83c408               add esp, 8
// 006341a0  c21000               ret 0x10
// 006341a3  6681fb46e1           cmp bx, 0xe146
// 006341a8  0f8598000000         jne 0x634246
// 006341ae  83beb800000000       cmp dword ptr [esi + 0xb8], 0
// 006341b5  0f8e8b000000         jle 0x634246
// 006341bb  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 006341c1  8d54240c             lea edx, [esp + 0xc]
// 006341c5  52                   push edx
// 006341c6  6a00                 push 0
// 006341c8  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006341d0  8b01                 mov eax, dword ptr [ecx]
// 006341d2  8b4014               mov eax, dword ptr [eax + 0x14]
// 006341d5  6a00                 push 0
// 006341d7  6846e10000           push 0xe146
// 006341dc  ffd0                 call eax
// 006341de  85c0                 test eax, eax
// 006341e0  7464                 je 0x634246
// 006341e2  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 006341e8  8b96a0000000         mov edx, dword ptr [esi + 0xa0]
// 006341ee  8b4220               mov eax, dword ptr [edx + 0x20]
// 006341f1  81c100000100         add ecx, 0x10000
// 006341f7  51                   push ecx
// 006341f8  6a00                 push 0
// 006341fa  6865030000           push 0x365
// 006341ff  50                   push eax
// 00634200  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00634206  5f                   pop edi
// 00634207  5e                   pop esi
// 00634208  b801000000           mov eax, 1
// 0063420d  5b                   pop ebx
// 0063420e  83c408               add esp, 8
// 00634211  c21000               ret 0x10
// 00634214  83f81c               cmp eax, 0x1c
// 00634217  7421                 je 0x63423a
// 00634219  3d12010000           cmp eax, 0x112
// 0063421e  7526                 jne 0x634246
// 00634220  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00634224  85c0                 test eax, eax
// 00634226  7405                 je 0x63422d
// 00634228  6685c0               test ax, ax
// 0063422b  7419                 je 0x634246
// 0063422d  3d00f10000           cmp eax, 0xf100
// 00634232  7412                 je 0x634246
// 00634234  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 00634238  eb05                 jmp 0x63423f
// 0063423a  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0063423f  7505                 jne 0x634246
// 00634241  e82afaffff           call 0x633c70
// 00634246  5f                   pop edi
// 00634247  5e                   pop esi
// 00634248  33c0                 xor eax, eax
// 0063424a  5b                   pop ebx
// 0063424b  83c408               add esp, 8
// 0063424e  c21000               ret 0x10


typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef void* HWND;

extern "C" __declspec(dllimport) HWND __stdcall GetFocus();
extern "C" __declspec(dllimport) int __stdcall SendMessageA(HWND, UINT, WPARAM, LPARAM);
extern "C" __declspec(dllimport) int __stdcall RedrawWindow(HWND, const void*, void*, UINT);

struct CRuntimeClass;
struct CmdHandlerInfo { void* pTarget; void* pmf; };

struct CXTPRefreshable {
    void RefreshMetrics();
};
struct CXTPImageManager {
    void RefreshAll();
};
CXTPRefreshable* XTPPaintManagerGlobal();

struct CXTPWndBase {
    static CXTPWndBase* __stdcall FromHandle(HWND);
    int IsKindOf(CRuntimeClass*) const;
    virtual void v00(); 
};
CRuntimeClass* GetThisClassCmd();

struct CXTPCommandBar {
    char pad0[0x4c];
    char* m_p4c;
    char pad1[0x5c - 0x50];
    int m_5c;
    char pad2[0x84 - 0x60];
    int m_84;
    char pad3[0xa0 - 0x88];
    char* m_a0;
    char pad4[0xb8 - 0xa4];
    int m_b8;

    char* GetControl(int);
    char* GetPaintManager();
    CXTPImageManager* GetImageManager();
    void RecalcLayout();
    void OnHide();
    int OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

int CXTPCommandBar::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    if (message == 0x363) {
        for (int i = 0; i < m_84; i++) {
            char* p = GetControl(i);
            if (*(int*)(p + 0xfc) == 4)
                (*(void (__thiscall**)(void*, int, int))(*(int*)p + 0x1e0))(p, 1, 1);
        }
        return 0;
    }
    if (message == 0x15) {
        XTPPaintManagerGlobal()->RefreshMetrics();
        char* q = GetPaintManager();
        (*(void (__thiscall**)(void*))(*(int*)q + 0xa8))(q);
        GetImageManager()->RefreshAll();
        RedrawWindow(*(HWND*)(m_a0 + 0x20), 0, 0, 0x105);
        RecalcLayout();
        return 0;
    }
    if (message == 0x1a) {
        char* q = GetPaintManager();
        (*(void (__thiscall**)(void*))(*(int*)q + 0xa8))(q);
        RedrawWindow(*(HWND*)(m_a0 + 0x20), 0, 0, 0x105);
        RecalcLayout();
        return 0;
    }
    if (message == 0x10) {
        if (*(int*)(m_p4c + 0x14) != 0)
            return 1;
    }
    else if (message == 0x111) {
        CXTPWndBase* p = CXTPWndBase::FromHandle(GetFocus());
        if (p != 0 && p->IsKindOf(GetThisClassCmd())
            && (*(int (__thiscall**)(void*, WPARAM, LPARAM))(*(int*)p + 0xf0))(p, wParam, lParam)) {
            if (pResult != 0)
                *pResult = 1;
            return 1;
        }
        if ((unsigned short)wParam == 0xe146 && m_b8 > 0) {
            CmdHandlerInfo info;
            info.pTarget = 0;
            if ((*(int (__thiscall**)(void*, UINT, int, void*, CmdHandlerInfo*))(*(int*)m_a0 + 0x14))(m_a0, 0xe146, 0, 0, &info)) {
                SendMessageA(*(HWND*)(m_a0 + 0x20), 0x365, 0, m_b8 + 0x10000);
                return 1;
            }
        }
        return 0;
    }
    if (message == 0x1c) {
        if (wParam == 0)
            OnHide();
        return 0;
    }
    if (message == 0x112) {
        if (wParam != 0 && (unsigned short)wParam == 0)
            return 0;
        if (wParam == 0xf100)
            return 0;
        if (m_5c == 0)
            OnHide();
        return 0;
    }
    return 0;
}
