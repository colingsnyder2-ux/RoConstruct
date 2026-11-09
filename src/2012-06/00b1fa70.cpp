// roc 2012-06 00b1fa70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa70
//
// 00b1fa70  b9a834e500           mov ecx, 0xe534a8
// 00b1fa75  e97624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fa70 { void m(); };
extern T_func_00b1fa70 G1_func_00b1fa70;
void func_00b1fa70()
{
    G1_func_00b1fa70.m();
}
