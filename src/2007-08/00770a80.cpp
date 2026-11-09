// from server: 100% by colin
// roc 2007-08 00770a80  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00770a80
//
// 00770a80  68b90b0000           push 0xbb9
// 00770a85  6848677a00           push 0x7a6748
// 00770a8a  e8b1bedbff           call 0x52c940
// 00770a8f  83c408               add esp, 8
// 00770a92  a314148c00           mov dword ptr [0x8c1414], eax
// 00770a97  c3                   ret 

extern "C" void* __cdecl sub_52c940(const char*, int);

void* g_8c1414;

void __cdecl sub_770a80()
{
    g_8c1414 = sub_52c940((const char*)0x7a6748, 0xbb9);
}
