// roc 2012-06 00b1db50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1db50
//
// 00b1db50  b928f4e400           mov ecx, 0xe4f428
// 00b1db55  e9e61ed6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1db50 { void m(); };
extern T_func_00b1db50 G1_func_00b1db50;
void func_00b1db50()
{
    G1_func_00b1db50.m();
}
