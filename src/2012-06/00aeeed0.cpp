// roc 2012-06 00aeeed0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeeed0
//
// 00aeeed0  b91737e200           mov ecx, 0xe23717
// 00aeeed5  e9266ef0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeeed0 { void m(); };
extern T_func_00aeeed0 G1_func_00aeeed0;
void func_00aeeed0()
{
    G1_func_00aeeed0.m();
}
