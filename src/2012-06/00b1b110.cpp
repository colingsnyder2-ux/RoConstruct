// roc 2012-06 00b1b110  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b110
//
// 00b1b110  b980e3e300           mov ecx, 0xe3e380
// 00b1b115  e956488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b110 { void m(); };
extern T_func_00b1b110 G1_func_00b1b110;
void func_00b1b110()
{
    G1_func_00b1b110.m();
}
