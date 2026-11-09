// roc 2012-06 00b1afb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1afb0
//
// 00b1afb0  b9700de400           mov ecx, 0xe40d70
// 00b1afb5  e9b6498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1afb0 { void m(); };
extern T_func_00b1afb0 G1_func_00b1afb0;
void func_00b1afb0()
{
    G1_func_00b1afb0.m();
}
