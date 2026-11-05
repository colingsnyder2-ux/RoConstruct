// roc 2012-06 00b127c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127c0
//
// 00b127c0  b96ca6e100           mov ecx, 0xe1a66c
// 00b127c5  e9662397ff           jmp 0x484b30
// auto-matched from its assembly shape

struct T_func_00b127c0 { void m(); };
extern T_func_00b127c0 G1_func_00b127c0;
void func_00b127c0()
{
    G1_func_00b127c0.m();
}
