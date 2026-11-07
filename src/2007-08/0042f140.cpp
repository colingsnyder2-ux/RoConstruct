// from server: 100% by Intel
// from server: 96% by EspClaude
// roc 2007-08 0042f140  unit: CMainFrame  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042f140
//
// 0042f140  56                   push esi
// 0042f141  8bf1                 mov esi, ecx
// 0042f143  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042f147  e8e0132000           call 0x63052c
// 0042f14c  85c0                 test eax, eax
// 0042f14e  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0042f154  7504                 jne 0x42f15a
// 0042f156  5e                   pop esi
// 0042f157  c20400               ret 4
// 0042f15a  56                   push esi
// 0042f15b  8bc8                 mov ecx, eax
// 0042f15d  e8fe382000           call 0x632a60
// 0042f162  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0042f168  e8332b2000           call 0x631ca0
// 0042f16d  b801000000           mov eax, 1
// 0042f172  5e                   pop esi
// 0042f173  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0042ef40  unit: CMainFrame  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042ef40
//
// 0042ef40  56                   push esi
// 0042ef41  8bf1                 mov esi, ecx
// 0042ef43  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042ef47  e876202700           call 0x6a0fc2
// 0042ef4c  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0042ef52  85c0                 test eax, eax
// 0042ef54  7504                 jne 0x42ef5a
// 0042ef56  5e                   pop esi
// 0042ef57  c20400               ret 4
// 0042ef5a  56                   push esi
// 0042ef5b  8bc8                 mov ecx, eax
// 0042ef5d  e80e492700           call 0x6a3870
// 0042ef62  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0042ef68  e8e3392700           call 0x6a2950
// 0042ef6d  b801000000           mov eax, 1
// 0042ef72  5e                   pop esi
// 0042ef73  c20400               ret 4

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
    char padding[0xd8];
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
