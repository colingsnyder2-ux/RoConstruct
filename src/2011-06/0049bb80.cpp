// from server: 100% by Yeetserama
// roc 2011-06 0049bb80  unit: CWebToolbox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049bb80
//
// 0049bb80  56                   push esi
// 0049bb81  8bf1                 mov esi, ecx
// 0049bb83  e8a6ea3600           call 0x80a62e
// 0049bb88  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0049bb8e  5e                   pop esi
// 0049bb8f  85c9                 test ecx, ecx
// 0049bb91  7405                 je 0x49bb98
// 0049bb93  e868e83600           call 0x80a400
// 0049bb98  c20c00               ret 0xc
// copied from an identical function in another client (function ?f@CWebToolbox@ns_ROCX000001@@QAEXHHH@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
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
