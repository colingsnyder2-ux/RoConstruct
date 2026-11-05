// roc 2012-06 00b13540  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13540
//
// 00b13540  b90c15e200           mov ecx, 0xe2150c
// 00b13545  e94641a1ff           jmp 0x527690
// auto-matched from its assembly shape

struct T_func_00b13540 { void m(); };
extern T_func_00b13540 G1_func_00b13540;
void func_00b13540()
{
    G1_func_00b13540.m();
}
