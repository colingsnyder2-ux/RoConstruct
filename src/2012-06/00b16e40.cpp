// roc 2012-06 00b16e40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e40
//
// 00b16e40  b940f6e200           mov ecx, 0xe2f640
// 00b16e45  e9f68bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16e40 { void m(); };
extern T_func_00b16e40 G1_func_00b16e40;
void func_00b16e40()
{
    G1_func_00b16e40.m();
}
