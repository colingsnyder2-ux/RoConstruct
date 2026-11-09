// roc 2012-06 00b18200  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18200
//
// 00b18200  b9a853e300           mov ecx, 0xe353a8
// 00b18205  e92649c2ff           jmp 0x73cb30
// auto-matched from its assembly shape

struct T_func_00b18200 { void m(); };
extern T_func_00b18200 G1_func_00b18200;
void func_00b18200()
{
    G1_func_00b18200.m();
}
