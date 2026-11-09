// roc 2012-06 00b12ad0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ad0
//
// 00b12ad0  b914c4e100           mov ecx, 0xe1c414
// 00b12ad5  e9a6019cff           jmp 0x4d2c80
// auto-matched from its assembly shape

struct T_func_00b12ad0 { void m(); };
extern T_func_00b12ad0 G1_func_00b12ad0;
void func_00b12ad0()
{
    G1_func_00b12ad0.m();
}
