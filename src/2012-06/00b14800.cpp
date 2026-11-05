// roc 2012-06 00b14800  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14800
//
// 00b14800  b9a04ee200           mov ecx, 0xe24ea0
// 00b14805  e9a69fa6ff           jmp 0x57e7b0
// auto-matched from its assembly shape

struct T_func_00b14800 { void m(); };
extern T_func_00b14800 G1_func_00b14800;
void func_00b14800()
{
    G1_func_00b14800.m();
}
