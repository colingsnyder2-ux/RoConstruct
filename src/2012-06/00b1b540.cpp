// roc 2012-06 00b1b540  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b540
//
// 00b1b540  b9c886e400           mov ecx, 0xe486c8
// 00b1b545  e986a3c5ff           jmp 0x7758d0
// auto-matched from its assembly shape

struct T_func_00b1b540 { void m(); };
extern T_func_00b1b540 G1_func_00b1b540;
void func_00b1b540()
{
    G1_func_00b1b540.m();
}
