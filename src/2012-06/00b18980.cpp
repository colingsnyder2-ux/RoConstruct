// roc 2012-06 00b18980  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18980
//
// 00b18980  b91067e300           mov ecx, 0xe36710
// 00b18985  e9e66f8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18980 { void m(); };
extern T_func_00b18980 G1_func_00b18980;
void func_00b18980()
{
    G1_func_00b18980.m();
}
