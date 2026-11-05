// roc 2012-06 00b1f220  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f220
//
// 00b1f220  b9281fe500           mov ecx, 0xe51f28
// 00b1f225  e97661d6ff           jmp 0x8853a0
// auto-matched from its assembly shape

struct T_func_00b1f220 { void m(); };
extern T_func_00b1f220 G1_func_00b1f220;
void func_00b1f220()
{
    G1_func_00b1f220.m();
}
