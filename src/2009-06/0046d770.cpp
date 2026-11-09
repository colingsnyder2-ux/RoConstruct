// from server: 100% by EspClaude
// roc 2009-06 0046d770  unit: CWebToolbox  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d770
//
// 0046d770  8b442404             mov eax, dword ptr [esp + 4]
// 0046d774  56                   push esi
// 0046d775  50                   push eax
// 0046d776  8bf1                 mov esi, ecx
// 0046d778  e839c22a00           call 0x7199b6
// 0046d77d  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0046d783  5e                   pop esi
// 0046d784  85c9                 test ecx, ecx
// 0046d786  7405                 je 0x46d78d
// 0046d788  e84db62a00           call 0x718dda
// 0046d78d  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000027_0046a6d0@CWebToolbox@ns_ROCX000027@@QAEXH@Z)

namespace ns_ROCX000027 {
struct Child
{
    void update();
};

struct CWebToolbox
{
    char padding[0xF8];
    Child* child;

    void baseCall(int value);
    void fn_ROCX000027_0046a6d0(int value);
};

void CWebToolbox::fn_ROCX000027_0046a6d0(int value)
{
    baseCall(value);
    if (child)
        child->update();
}
}
