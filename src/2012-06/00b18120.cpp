// roc 2012-06 00b18120  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18120
//
// 00b18120  b9b847e300           mov ecx, 0xe347b8
// 00b18125  e946788fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18120 { void m(); };
extern T_func_00b18120 G1_func_00b18120;
void func_00b18120()
{
    G1_func_00b18120.m();
}
