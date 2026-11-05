// roc 2012-06 00b18970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18970
//
// 00b18970  b9f868e300           mov ecx, 0xe368f8
// 00b18975  e9f66f8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18970 { void m(); };
extern T_func_00b18970 G1_func_00b18970;
void func_00b18970()
{
    G1_func_00b18970.m();
}
