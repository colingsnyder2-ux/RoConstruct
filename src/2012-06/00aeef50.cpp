// roc 2012-06 00aeef50  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef50
//
// 00aeef50  b9f03be200           mov ecx, 0xe23bf0
// 00aeef55  e9d62aa7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aeef50 { void m(); };
extern T_func_00aeef50 G1_func_00aeef50;
void func_00aeef50()
{
    G1_func_00aeef50.m();
}
