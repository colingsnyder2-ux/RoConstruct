// roc 2012-06 00b127f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127f0
//
// 00b127f0  b930a9e100           mov ecx, 0xe1a930
// 00b127f5  e9566a98ff           jmp 0x499250
// auto-matched from its assembly shape

struct T_func_00b127f0 { void m(); };
extern T_func_00b127f0 G1_func_00b127f0;
void func_00b127f0()
{
    G1_func_00b127f0.m();
}
