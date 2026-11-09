// from server: 100% by colin
// roc 2007-08 00771ca0  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00771ca0
//
// 00771ca0  68ea030000           push 0x3ea
// 00771ca5  68f8af7a00           push 0x7aaff8
// 00771caa  e891acdbff           call 0x52c940
// 00771caf  83c408               add esp, 8
// 00771cb2  a3d0298c00           mov dword ptr [0x8c29d0], eax
// 00771cb7  c3                   ret 
// library rbxgs/v8xml\XmlElement.cpp (function ??__Etag_Position@@YAXXZ)

extern "C" void* __cdecl sub_52C940(const char*, unsigned int);

void* g_8c29d0;

void __cdecl init_Position()
{
    g_8c29d0 = sub_52C940((const char*)0x7aaff8, 0x3ea);
}
