// roc 2012-06 00b21840  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21840
//
// 00b21840  b910a4e500           mov ecx, 0xe5a410
// 00b21845  e9e66ff4ff           jmp 0xa68830
// auto-matched from its assembly shape

struct T_func_00b21840 { void m(); };
extern T_func_00b21840 G1_func_00b21840;
void func_00b21840()
{
    G1_func_00b21840.m();
}
