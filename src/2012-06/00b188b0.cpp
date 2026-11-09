// roc 2012-06 00b188b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b188b0
//
// 00b188b0  b92860e300           mov ecx, 0xe36028
// 00b188b5  e93696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b188b0 { void m(); };
extern T_func_00b188b0 G1_func_00b188b0;
void func_00b188b0()
{
    G1_func_00b188b0.m();
}
