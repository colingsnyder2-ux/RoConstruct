// roc 2012-06 009d1150  unit: CXTPControls  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d1150
//
// 009d1150  8b442404             mov eax, dword ptr [esp + 4]
// 009d1154  6aff                 push -1
// 009d1156  50                   push eax
// 009d1157  e8b4ffffff           call 0x9d1110
// 009d115c  c20400               ret 4
// copied from an identical function in another client (function ?func_0067C5A0@CXTPControls@ns_ROCX00002b@@QAEXH@Z)

namespace ns_ROCX00002b {
struct CXTPControls
{
    void sub_0067C560(int, int);
    void func_0067C5A0(int);
};

void CXTPControls::func_0067C5A0(int a)
{
    sub_0067C560(a, -1);
}
}
