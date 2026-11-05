// roc 2012-06 00b18470  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18470
//
// 00b18470  b90058e300           mov ecx, 0xe35800
// 00b18475  e9c675d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b18470 { void m(); };
extern T_func_00b18470 G1_func_00b18470;
void func_00b18470()
{
    G1_func_00b18470.m();
}
