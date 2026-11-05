// roc 2012-06 004b0c70  unit: CWebToolbox  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0c70
//
// 004b0c70  e8691a4d00           call 0x9826de
// 004b0c75  8b442404             mov eax, dword ptr [esp + 4]
// 004b0c79  c7400c32000000       mov dword ptr [eax + 0xc], 0x32
// 004b0c80  c20400               ret 4
// copied from an identical function in another client (function ?setValue@CWebToolbox@ns_ROCX000002@@QAEXPAH@Z)

namespace ns_ROCX000002 {
extern "C" void __cdecl helper_63023e();

struct CWebToolbox {
    void setValue(int* p);
};

void CWebToolbox::setValue(int* p) {
    helper_63023e();
    p[3] = 0x32;
}
}
