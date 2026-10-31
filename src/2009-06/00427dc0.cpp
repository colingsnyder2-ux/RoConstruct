// from server: 100% by EspClaude
// roc 2009-06 00427dc0  unit: CMainFrame  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427dc0
//
// 00427dc0  56                   push esi
// 00427dc1  8bf1                 mov esi, ecx
// 00427dc3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00427dc7  e868162f00           call 0x719434
// 00427dcc  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00427dd2  85c0                 test eax, eax
// 00427dd4  7504                 jne 0x427dda
// 00427dd6  5e                   pop esi
// 00427dd7  c20400               ret 4
// 00427dda  56                   push esi
// 00427ddb  8bc8                 mov ecx, eax
// 00427ddd  e88e233000           call 0x72a170
// 00427de2  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00427de8  e803163000           call 0x7293f0
// 00427ded  b801000000           mov eax, 1
// 00427df2  5e                   pop esi
// 00427df3  c20400               ret 4
// copied from an identical function in another client (function ?Setup@CMainFrame@ns_ROCX0000f1@@QAEHPAUSource@2@@Z)

namespace ns_ROCX0000f1 {
struct CMainFrame;
struct CommandBars;

struct Source {
    CommandBars* Get();
};

struct CommandBars {
    void SetFrame(CMainFrame* frame);
    void Initialize();
};

struct CMainFrame {
    char padding[0xec];
    CommandBars* bars;
    int Setup(Source* source);
};

int CMainFrame::Setup(Source* source)
{
    bars = source->Get();
    if (!bars)
        return 0;

    bars->SetFrame(this);
    bars->Initialize();
    return 1;
}
}
