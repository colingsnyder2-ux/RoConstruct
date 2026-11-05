// from server: 100% by colin
// roc 2007-08 00770430  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00770430
//
// 00770430  68d0070000           push 0x7d0
// 00770435  68e08e8900           push 0x898ee0
// 0077043a  e801c5dbff           call 0x52c940
// 0077043f  83c408               add esp, 8
// 00770442  a3500e8c00           mov dword ptr [0x8c0e50], eax
// 00770447  c3                   ret 

extern "C" void* __cdecl sub_52C940(const char*, unsigned int);

void* g_8C0E50;

void init_8C0E50()
{
    g_8C0E50 = sub_52C940((const char*)0x898ee0, 0x7d0);
}
