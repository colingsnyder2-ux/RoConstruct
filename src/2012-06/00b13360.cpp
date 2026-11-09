// roc 2012-06 00b13360  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13360
//
// 00b13360  b988f1e100           mov ecx, 0xe1f188
// 00b13365  e906c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13360 { void m(); };
extern T_func_00b13360 G1_func_00b13360;
void func_00b13360()
{
    G1_func_00b13360.m();
}
