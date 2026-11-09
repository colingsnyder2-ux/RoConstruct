// roc 2012-06 00b1a980  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a980
//
// 00b1a980  b9d095e300           mov ecx, 0xe395d0
// 00b1a985  e9c642c5ff           jmp 0x76ec50
// auto-matched from its assembly shape

struct T_func_00b1a980 { void m(); };
extern T_func_00b1a980 G1_func_00b1a980;
void func_00b1a980()
{
    G1_func_00b1a980.m();
}
