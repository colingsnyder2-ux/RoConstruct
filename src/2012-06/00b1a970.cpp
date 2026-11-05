// roc 2012-06 00b1a970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a970
//
// 00b1a970  b98096e300           mov ecx, 0xe39680
// 00b1a975  e97645c5ff           jmp 0x76eef0
// auto-matched from its assembly shape

struct T_func_00b1a970 { void m(); };
extern T_func_00b1a970 G1_func_00b1a970;
void func_00b1a970()
{
    G1_func_00b1a970.m();
}
