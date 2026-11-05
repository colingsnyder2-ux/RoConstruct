// from server: 100% by tester
// roc 2008-06 0051dd60  unit: seg_00510000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0051dd60
//
// 0051dd60  6a00                 push 0
// 0051dd62  6a00                 push 0
// 0051dd64  6a00                 push 0
// 0051dd66  e8a5a32800           call 0x7a8110
// 0051dd6b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0051dd6f  898110010000         mov dword ptr [ecx + 0x110], eax
// 0051dd75  c3                   ret 
// copied from an identical function in another client (function ?DialogTemplate_init@ns_ROCX000000@@YAXPAUDialogTemplate@1@@Z)

namespace ns_ROCX000000 {
struct DialogTemplate {
    char pad[0x110];
    int field110;
};

extern "C" int __stdcall sub_72D160(int, int, int);

void __cdecl DialogTemplate_init(DialogTemplate* self) {
    self->field110 = sub_72D160(0, 0, 0);
}
}
