// roc 2012-06 00b1d540  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d540
//
// 00b1d540  b9b4e0e400           mov ecx, 0xe4e0b4
// 00b1d545  e9a649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d540 { void m(); };
extern T_func_00b1d540 G1_func_00b1d540;
void func_00b1d540()
{
    G1_func_00b1d540.m();
}
