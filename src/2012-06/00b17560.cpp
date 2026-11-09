// roc 2012-06 00b17560  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17560
//
// 00b17560  b94819e300           mov ecx, 0xe31948
// 00b17565  e986a9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17560 { void m(); };
extern T_func_00b17560 G1_func_00b17560;
void func_00b17560()
{
    G1_func_00b17560.m();
}
