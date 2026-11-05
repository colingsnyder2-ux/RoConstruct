// roc 2012-06 00b1b340  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b340
//
// 00b1b340  b9c8a0e300           mov ecx, 0xe3a0c8
// 00b1b345  e926468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b340 { void m(); };
extern T_func_00b1b340 G1_func_00b1b340;
void func_00b1b340()
{
    G1_func_00b1b340.m();
}
