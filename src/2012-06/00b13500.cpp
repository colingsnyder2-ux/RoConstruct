// roc 2012-06 00b13500  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13500
//
// 00b13500  b90415e200           mov ecx, 0xe21504
// 00b13505  e94653a1ff           jmp 0x528850
// auto-matched from its assembly shape

struct T_func_00b13500 { void m(); };
extern T_func_00b13500 G1_func_00b13500;
void func_00b13500()
{
    G1_func_00b13500.m();
}
