// from server: 100% by EspClaude
// roc 2009-06 0046d860  unit: CWebToolbox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d860
//
// 0046d860  56                   push esi
// 0046d861  8bf1                 mov esi, ecx
// 0046d863  e8a0b72a00           call 0x719008
// 0046d868  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0046d86e  5e                   pop esi
// 0046d86f  85c9                 test ecx, ecx
// 0046d871  7405                 je 0x46d878
// 0046d873  e862b52a00           call 0x718dda
// 0046d878  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@CWebToolbox@ns_ROCX00002b@@QAEXHHH@Z)

namespace ns_ROCX00002b {
struct Tool {
    void update();
};

struct CWebToolbox {
    char padding[0xf8];
    Tool* tool;

    void prepare();
    void f(int, int, int);
};

void CWebToolbox::f(int, int, int)
{
    prepare();
    if (tool)
        tool->update();
}
}
