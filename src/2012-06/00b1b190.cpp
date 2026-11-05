// roc 2012-06 00b1b190  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b190
//
// 00b1b190  b940d4e300           mov ecx, 0xe3d440
// 00b1b195  e9d6478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b190 { void m(); };
extern T_func_00b1b190 G1_func_00b1b190;
void func_00b1b190()
{
    G1_func_00b1b190.m();
}
