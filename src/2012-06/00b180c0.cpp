// roc 2012-06 00b180c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b180c0
//
// 00b180c0  b9c842e300           mov ecx, 0xe342c8
// 00b180c5  e9d6edc1ff           jmp 0x736ea0
// auto-matched from its assembly shape

struct T_func_00b180c0 { void m(); };
extern T_func_00b180c0 G1_func_00b180c0;
void func_00b180c0()
{
    G1_func_00b180c0.m();
}
