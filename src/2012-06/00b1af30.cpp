// roc 2012-06 00b1af30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af30
//
// 00b1af30  b9b01ce400           mov ecx, 0xe41cb0
// 00b1af35  e9364a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af30 { void m(); };
extern T_func_00b1af30 G1_func_00b1af30;
void func_00b1af30()
{
    G1_func_00b1af30.m();
}
