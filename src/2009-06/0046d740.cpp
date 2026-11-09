// from server: 100% by EspClaude
// roc 2009-06 0046d740  unit: CWebToolbox  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d740
//
// 0046d740  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046d744  8b542404             mov edx, dword ptr [esp + 4]
// 0046d748  56                   push esi
// 0046d749  8bf1                 mov esi, ecx
// 0046d74b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046d74f  50                   push eax
// 0046d750  51                   push ecx
// 0046d751  52                   push edx
// 0046d752  8bce                 mov ecx, esi
// 0046d754  e835b72a00           call 0x718e8e
// 0046d759  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0046d75f  5e                   pop esi
// 0046d760  85c9                 test ecx, ecx
// 0046d762  7405                 je 0x46d769
// 0046d764  e871b62a00           call 0x718dda
// 0046d769  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000026_0046a6a0@CWebToolbox@ns_ROCX000026@@QAEXHHH@Z)

namespace ns_ROCX000026 {
struct Tool {
    void update();
};

struct CWebToolbox {
    char padding[0xF8];
    Tool* tool;

    void baseFunction(int a, int b, int c);
    void fn_ROCX000026_0046a6a0(int a, int b, int c);
};

void CWebToolbox::fn_ROCX000026_0046a6a0(int a, int b, int c)
{
    baseFunction(a, b, c);
    if (tool)
        tool->update();
}
}
