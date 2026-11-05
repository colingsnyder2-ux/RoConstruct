// from server: 100% by colin
// roc 2007-08 00771c80  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00771c80
//
// 00771c80  68e9030000           push 0x3e9
// 00771c85  68f0af7a00           push 0x7aaff0
// 00771c8a  e8b1acdbff           call 0x52c940
// 00771c8f  83c408               add esp, 8
// 00771c92  a354298c00           mov dword ptr [0x8c2954], eax
// 00771c97  c3                   ret 

extern "C" void* __cdecl sub_52C940(int, const char*);

void* g_8C2954;

void init_8C2954()
{
    g_8C2954 = sub_52C940(0x3e9, "L$4d");
}
