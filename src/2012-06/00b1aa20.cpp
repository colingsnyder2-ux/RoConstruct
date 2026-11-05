// roc 2012-06 00b1aa20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa20
//
// 00b1aa20  b9f08ee300           mov ecx, 0xe38ef0
// 00b1aa25  e9162bc5ff           jmp 0x76d540
// auto-matched from its assembly shape

struct T_func_00b1aa20 { void m(); };
extern T_func_00b1aa20 G1_func_00b1aa20;
void func_00b1aa20()
{
    G1_func_00b1aa20.m();
}
