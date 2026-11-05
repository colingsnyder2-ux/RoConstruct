// roc 2012-06 00b1a9b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9b0
//
// 00b1a9b0  b9c093e300           mov ecx, 0xe393c0
// 00b1a9b5  e9b63ac5ff           jmp 0x76e470
// auto-matched from its assembly shape

struct T_func_00b1a9b0 { void m(); };
extern T_func_00b1a9b0 G1_func_00b1a9b0;
void func_00b1a9b0()
{
    G1_func_00b1a9b0.m();
}
