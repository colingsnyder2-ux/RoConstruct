// from server: 100% by EspClaude
// roc 2009-06 00447750  unit: CRobloxModule  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447750
//
// 00447750  e8731f2d00           call 0x7196c8
// 00447755  e89c152d00           call 0x718cf6
// 0044775a  8b4034               mov eax, dword ptr [eax + 0x34]
// 0044775d  c3                   ret 
// copied from an identical function in another client (function ?wrapper@ns_ROCX000000@@YAHXZ)

namespace ns_ROCX000000 {
struct Result {
    char padding[0x34];
    int value;
};

extern "C" void __cdecl sub_6A1250();
extern "C" Result* __cdecl sub_6A0926();

int __cdecl wrapper()
{
    sub_6A1250();
    return sub_6A0926()->value;
}
}
