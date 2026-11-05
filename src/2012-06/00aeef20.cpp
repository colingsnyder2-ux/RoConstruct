// roc 2012-06 00aeef20  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef20
//
// 00aeef20  b91237e200           mov ecx, 0xe23712
// 00aeef25  e9d66df0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeef20 { void m(); };
extern T_func_00aeef20 G1_func_00aeef20;
void func_00aeef20()
{
    G1_func_00aeef20.m();
}
