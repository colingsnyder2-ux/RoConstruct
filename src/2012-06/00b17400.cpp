// roc 2012-06 00b17400  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17400
//
// 00b17400  b97014e300           mov ecx, 0xe31470
// 00b17405  e966858fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17400 { void m(); };
extern T_func_00b17400 G1_func_00b17400;
void func_00b17400()
{
    G1_func_00b17400.m();
}
