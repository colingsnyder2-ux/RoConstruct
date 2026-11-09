// from server: 100% by colin
// roc 2007-08 00770a60  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00770a60
//
// 00770a60  68b80b0000           push 0xbb8
// 00770a65  68d47e7800           push 0x787ed4
// 00770a6a  e8d1bedbff           call 0x52c940
// 00770a6f  83c408               add esp, 8
// 00770a72  a3a4158c00           mov dword ptr [0x8c15a4], eax
// 00770a77  c3                   ret 
// library rbxgs/v8xml\XmlElement.cpp (function ??__Ename_root@@YAXXZ)

extern "C" void* __cdecl sub_52c940(const char*, unsigned int);

void* g_8c15a4;

void init_name_root()
{
    g_8c15a4 = sub_52c940((const char*)0x787ed4, 0xbb8);
}
