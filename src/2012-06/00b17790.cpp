// roc 2012-06 00b17790  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17790
//
// 00b17790  b9b020e300           mov ecx, 0xe320b0
// 00b17795  e956a7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17790 { void m(); };
extern T_func_00b17790 G1_func_00b17790;
void func_00b17790()
{
    G1_func_00b17790.m();
}
