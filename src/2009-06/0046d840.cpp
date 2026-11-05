// from server: 100% by EspClaude
// roc 2009-06 0046d840  unit: CWebToolbox  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d840
//
// 0046d840  e8c3b72a00           call 0x719008
// 0046d845  8b442404             mov eax, dword ptr [esp + 4]
// 0046d849  c7400c32000000       mov dword ptr [eax + 0xc], 0x32
// 0046d850  c20400               ret 4
// copied from an identical function in another client (function ?f@CWebToolbox@ns_ROCX00002a@@QAEXPAU12@@Z)

namespace ns_ROCX00002a {
extern "C" void __cdecl fn_ROCX00002a_006a0c68();

struct CWebToolbox
{
    void f(CWebToolbox* value);
};

void CWebToolbox::f(CWebToolbox* value)
{
    fn_ROCX00002a_006a0c68();
    *(int*)((char*)value + 12) = 50;
}
}
