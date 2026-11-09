// roc 2012-06 00b1b140  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b140
//
// 00b1b140  b9c8dde300           mov ecx, 0xe3ddc8
// 00b1b145  e926488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b140 { void m(); };
extern T_func_00b1b140 G1_func_00b1b140;
void func_00b1b140()
{
    G1_func_00b1b140.m();
}
