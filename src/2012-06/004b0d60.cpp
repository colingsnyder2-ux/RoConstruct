// from server: 100% by Xemicl
// roc 2012-06 004b0d60  unit: CWebToolbox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0d60
//
// 004b0d60  56                   push esi
// 004b0d61  8bf1                 mov esi, ecx
// 004b0d63  e876194d00           call 0x9826de
// 004b0d68  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 004b0d6e  5e                   pop esi
// 004b0d6f  85c9                 test ecx, ecx
// 004b0d71  7405                 je 0x4b0d78
// 004b0d73  e82c174d00           call 0x9824a4
// 004b0d78  c20c00               ret 0xc
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