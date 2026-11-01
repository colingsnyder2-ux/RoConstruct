// from server: 100% by EspClaude
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
