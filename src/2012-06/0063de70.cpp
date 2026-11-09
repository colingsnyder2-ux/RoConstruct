// roc 2012-06 0063de70  unit: seg_00630000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063de70
//
// 0063de70  6a00                 push 0
// 0063de72  6a00                 push 0
// 0063de74  6a00                 push 0
// 0063de76  e8e5090100           call 0x64e860
// 0063de7b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063de7f  898110010000         mov dword ptr [ecx + 0x110], eax
// 0063de85  c3                   ret 
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
