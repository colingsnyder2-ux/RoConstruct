// roc 2012-06 00b1fc90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fc90
//
// 00b1fc90  b95839e500           mov ecx, 0xe53958
// 00b1fc95  e95622a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fc90 { void m(); };
extern T_func_00b1fc90 G1_func_00b1fc90;
void func_00b1fc90()
{
    G1_func_00b1fc90.m();
}
