// roc 2012-06 00b20260  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20260
//
// 00b20260  b9d03fe500           mov ecx, 0xe53fd0
// 00b20265  e906f78eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20260 { void m(); };
extern T_func_00b20260 G1_func_00b20260;
void func_00b20260()
{
    G1_func_00b20260.m();
}
