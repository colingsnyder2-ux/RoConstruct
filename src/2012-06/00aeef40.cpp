// roc 2012-06 00aeef40  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef40
//
// 00aeef40  b91c37e200           mov ecx, 0xe2371c
// 00aeef45  e9e62aa7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aeef40 { void m(); };
extern T_func_00aeef40 G1_func_00aeef40;
void func_00aeef40()
{
    G1_func_00aeef40.m();
}
