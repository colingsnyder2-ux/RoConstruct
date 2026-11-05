// roc 2012-06 00b11840  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11840
//
// 00b11840  b91c81e100           mov ecx, 0xe1811c
// 00b11845  e956da90ff           jmp 0x41f2a0
// auto-matched from its assembly shape

struct T_func_00b11840 { void m(); };
extern T_func_00b11840 G1_func_00b11840;
void func_00b11840()
{
    G1_func_00b11840.m();
}
