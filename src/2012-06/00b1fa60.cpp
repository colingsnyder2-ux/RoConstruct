// roc 2012-06 00b1fa60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa60
//
// 00b1fa60  b9d834e500           mov ecx, 0xe534d8
// 00b1fa65  e98624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa60 { void m(); };
extern T_func_00b1fa60 G1_func_00b1fa60;
void func_00b1fa60()
{
    G1_func_00b1fa60.m();
}
