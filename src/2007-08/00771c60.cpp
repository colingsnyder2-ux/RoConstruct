// from server: 100% by colin
// roc 2007-08 00771c60  unit: seg_00770000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00771c60
//
// 00771c60  68e8030000           push 0x3e8
// 00771c65  6820048a00           push 0x8a0420
// 00771c6a  e8d1acdbff           call 0x52c940
// 00771c6f  83c408               add esp, 8
// 00771c72  a364288c00           mov dword ptr [0x8c2864], eax
// 00771c77  c3                   ret 

extern "C" void* __cdecl sub_52C940(unsigned int, void*);
extern unsigned char data_8A0420;
void* g_8C2864;

void sub_771C60()
{
    g_8C2864 = sub_52C940(0x3e8, &data_8A0420);
}
