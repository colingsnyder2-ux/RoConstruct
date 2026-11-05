// from server: 100% by EspClaude
// roc 2009-06 00428d50  unit: MyXTPCommandBars  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428d50
//
// 00428d50  56                   push esi
// 00428d51  57                   push edi
// 00428d52  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00428d56  837f0400             cmp dword ptr [edi + 4], 0
// 00428d5a  8bf1                 mov esi, ecx
// 00428d5c  7448                 je 0x428da6
// 00428d5e  8b4714               mov eax, dword ptr [edi + 0x14]
// 00428d61  68a8138b00           push 0x8b13a8
// 00428d66  50                   push eax
// 00428d67  ff1544e98900         call dword ptr [0x89e944]
// 00428d6d  83c408               add esp, 8
// 00428d70  85c0                 test eax, eax
// 00428d72  7532                 jne 0x428da6
// 00428d74  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00428d7a  50                   push eax
// 00428d7b  e830de3300           call 0x766bb0
// 00428d80  83c404               add esp, 4
// 00428d83  6890010000           push 0x190
// 00428d88  8bf0                 mov esi, eax
// 00428d8a  8b4714               mov eax, dword ptr [edi + 0x14]
// 00428d8d  68e9030000           push 0x3e9
// 00428d92  50                   push eax
// 00428d93  8bce                 mov ecx, esi
// 00428d95  e866de3300           call 0x766c00
// 00428d9a  8937                 mov dword ptr [edi], esi
// 00428d9c  5f                   pop edi
// 00428d9d  b801000000           mov eax, 1
// 00428da2  5e                   pop esi
// 00428da3  c20400               ret 4
// 00428da6  5f                   pop edi
// 00428da7  33c0                 xor eax, eax
// 00428da9  5e                   pop esi
// 00428daa  c20400               ret 4
// copied from an identical function in another client (function ?CreatePopup@CMainFrame@ns_ROCX0000f8@@QAEHPAUPopupRequest@2@@Z)

namespace ns_ROCX0000f8 {
// from server: 93% by king_originala
// roc 2008-06 0042fcf0  unit: CMainFrame  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042fcf0
//
// 0042fcf0  56                   push esi
// 0042fcf1  57                   push edi
// 0042fcf2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042fcf6  837f0400             cmp dword ptr [edi + 4], 0
// 0042fcfa  8bf1                 mov esi, ecx
// 0042fcfc  7448                 je 0x42fd46
// 0042fcfe  8b4714               mov eax, dword ptr [edi + 0x14]
// 0042fd01  68cc0d8100           push 0x810dcc
// 0042fd06  50                   push eax
// 0042fd07  ff153c288000         call dword ptr [0x80283c]
// 0042fd0d  83c408               add esp, 8
// 0042fd10  85c0                 test eax, eax
// 0042fd12  7532                 jne 0x42fd46
// 0042fd14  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 0042fd1a  50                   push eax
// 0042fd1b  e8b0e42b00           call 0x6ee1d0
// 0042fd20  83c404               add esp, 4
// 0042fd23  6890010000           push 0x190
// 0042fd28  8bf0                 mov esi, eax
// 0042fd2a  8b4714               mov eax, dword ptr [edi + 0x14]
// 0042fd2d  68e9030000           push 0x3e9
// 0042fd32  50                   push eax
// 0042fd33  8bce                 mov ecx, esi
// 0042fd35  e8e6e42b00           call 0x6ee220
// 0042fd3a  8937                 mov dword ptr [edi], esi
// 0042fd3c  5f                   pop edi
// 0042fd3d  b801000000           mov eax, 1
// 0042fd42  5e                   pop esi
// 0042fd43  c20400               ret 4
// 0042fd46  5f                   pop edi
// 0042fd47  33c0                 xor eax, eax
// 0042fd49  5e                   pop esi
// 0042fd4a  c20400               ret 4

extern "C" __declspec(dllimport) int __cdecl _mbscmp(const unsigned char *, const unsigned char *);

struct CommandBars;

struct PopupBar {
    static PopupBar * __cdecl CreatePopupBar(CommandBars *);
    void SetTitle(const char *, unsigned int, int);
};

struct Str { const char *p; operator const char *() const { return p; } };

struct PopupRequest {
    PopupBar *popup;
    int enabled;
    unsigned char reserved[12];
    Str title;
};

struct CMainFrame {
    unsigned char reserved[0xec];
    CommandBars *commandBars;

    CommandBars *GetCommandBars() const { return commandBars; }
    int CreatePopup(PopupRequest *);
};

int CMainFrame::CreatePopup(PopupRequest *request)
{
    if (request->enabled &&
        _mbscmp((const unsigned char *)(const char *)request->title,
                (const unsigned char *)"Camera Positioning") == 0)
    {
        PopupBar *popup = PopupBar::CreatePopupBar(GetCommandBars());
        popup->SetTitle(request->title, 1001, 400);
        request->popup = popup;
        return 1;
    }
    return 0;
}
}
