// roc 2012-06 00aeef10  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef10
//
// 00aeef10  b91637e200           mov ecx, 0xe23716
// 00aeef15  e9e66df0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeef10 { void m(); };
extern T_func_00aeef10 G1_func_00aeef10;
void func_00aeef10()
{
    G1_func_00aeef10.m();
}
