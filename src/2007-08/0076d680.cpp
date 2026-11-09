// from server: 100% by colin
// roc 2007-08 0076d680  unit: seg_00760000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076d680
//
// 0076d680  6aff                 push -1
// 0076d682  6810617900           push 0x796110
// 0076d687  e8b4f2dbff           call 0x52c940
// 0076d68c  83c408               add esp, 8
// 0076d68f  a320cf8b00           mov dword ptr [0x8bcf20], eax
// 0076d694  c3                   ret

extern "C" int __cdecl sub_0052C940(void*, void*);

int g_008BCF20;

void sub_0076D680()
{
    g_008BCF20 = sub_0052C940((void*)0x00796110, (void*)0xFFFFFFFF);
}
