// roc 2012-06 00b1fb50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fb50
//
// 00b1fb50  b92837e500           mov ecx, 0xe53728
// 00b1fb55  e9e6fed5ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1fb50 { void m(); };
extern T_func_00b1fb50 G1_func_00b1fb50;
void func_00b1fb50()
{
    G1_func_00b1fb50.m();
}
