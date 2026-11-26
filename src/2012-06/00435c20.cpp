// from server: 100% by Xemicl
// roc 2012-06 00435c20  unit: CMainFrame  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435c20
//
// 00435c20  56                   push esi
// 00435c21  8bf1                 mov esi, ecx
// 00435c23  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00435c27  e8c0ce5400           call 0x982aec
// 00435c2c  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00435c32  85c0                 test eax, eax
// 00435c34  7504                 jne 0x435c3a
// 00435c36  5e                   pop esi
// 00435c37  c20400               ret 4
// 00435c3a  56                   push esi
// 00435c3b  8bc8                 mov ecx, eax
// 00435c3d  e84ed35600           call 0x9a2f90
// 00435c42  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00435c48  e813c65600           call 0x9a2260
// 00435c4d  b801000000           mov eax, 1
// 00435c52  5e                   pop esi
// 00435c53  c20400               ret 4
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