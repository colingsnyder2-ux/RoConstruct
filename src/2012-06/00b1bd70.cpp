// roc 2012-06 00b1bd70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bd70
//
// 00b1bd70  b9689fe400           mov ecx, 0xe49f68
// 00b1bd75  e97661a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bd70 { void m(); };
extern T_func_00b1bd70 G1_func_00b1bd70;
void func_00b1bd70()
{
    G1_func_00b1bd70.m();
}
