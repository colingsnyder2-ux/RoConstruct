// from server: 100% by Xemicl
// roc 2012-06 004b0c70  unit: CWebToolbox  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0c70
//
// 004b0c70  e8691a4d00           call 0x9826de
// 004b0c75  8b442404             mov eax, dword ptr [esp + 4]
// 004b0c79  c7400c32000000       mov dword ptr [eax + 0xc], 0x32
// 004b0c80  c20400               ret 4
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