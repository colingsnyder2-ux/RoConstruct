// roc 2012-06 00b14390  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14390
//
// 00b14390  b93842e200           mov ecx, 0xe24238
// 00b14395  e9d6c1a4ff           jmp 0x560570
// auto-matched from its assembly shape

struct T_func_00b14390 { void m(); };
extern T_func_00b14390 G1_func_00b14390;
void func_00b14390()
{
    G1_func_00b14390.m();
}
