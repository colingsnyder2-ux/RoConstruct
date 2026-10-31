// from server: 100% by EspClaude
// roc 2009-06 00445070  unit: CRbxPlayDocTemplate  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445070
//
// 00445070  56                   push esi
// 00445071  57                   push edi
// 00445072  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00445076  57                   push edi
// 00445077  8bf1                 mov esi, ecx
// 00445079  e8ea452d00           call 0x719668
// 0044507e  3bbe90000000         cmp edi, dword ptr [esi + 0x90]
// 00445084  750a                 jne 0x445090
// 00445086  c7869000000000000000 mov dword ptr [esi + 0x90], 0
// 00445090  5f                   pop edi
// 00445091  5e                   pop esi
// 00445092  c20400               ret 4
// copied from an identical function in another client (function ?method@CRbxPlayDocTemplate@ns_ROCX00000d@@QAEXPAX@Z)

namespace ns_ROCX00000d {
struct CRbxPlayDocTemplate
{
    void* pad[36];
    void* field_90;
    void method(void*);
};

extern "C" void __stdcall sub_006A11F6(void*);

void CRbxPlayDocTemplate::method(void* value)
{
    sub_006A11F6(value);
    if (value == field_90)
        field_90 = 0;
}
}
