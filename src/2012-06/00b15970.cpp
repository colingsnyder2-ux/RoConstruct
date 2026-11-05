// roc 2012-06 00b15970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15970
//
// 00b15970  b930a5e200           mov ecx, 0xe2a530
// 00b15975  e9f6b7b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b15970 { void m(); };
extern T_func_00b15970 G1_func_00b15970;
void func_00b15970()
{
    G1_func_00b15970.m();
}
