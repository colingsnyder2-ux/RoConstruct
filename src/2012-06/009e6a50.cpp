// roc 2012-06 009e6a50  unit: CXTThemeManagerStyle  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6a50
//
// 009e6a50  56                   push esi
// 009e6a51  8bf1                 mov esi, ecx
// 009e6a53  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009e6a57  8b06                 mov eax, dword ptr [esi]
// 009e6a59  8b5014               mov edx, dword ptr [eax + 0x14]
// 009e6a5c  51                   push ecx
// 009e6a5d  8bce                 mov ecx, esi
// 009e6a5f  ffd2                 call edx
// 009e6a61  50                   push eax
// 009e6a62  8bce                 mov ecx, esi
// 009e6a64  e887ffffff           call 0x9e69f0
// 009e6a69  5e                   pop esi
// 009e6a6a  c20400               ret 4
// copied from an identical function in another client (function ?method_691db0@CXTThemeManagerStyle@ns_ROCX00002c@@QAEHH@Z)

namespace ns_ROCX00002c {
struct CXTThemeManagerStyle {
    int method_691d60(int);
    int method_691db0(int);
};

int CXTThemeManagerStyle::method_691db0(int arg) {
    int v = (*(int (__thiscall **)(void *, int))((*(int *)this) + 0x14))(this, arg);
    return this->method_691d60(v);
}
}
