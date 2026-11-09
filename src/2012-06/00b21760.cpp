// roc 2012-06 00b21760  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21760
//
// 00b21760  b9f49be500           mov ecx, 0xe59bf4
// 00b21765  e98681f7ff           jmp 0xa998f0
// auto-matched from its assembly shape

struct T_func_00b21760 { void m(); };
extern T_func_00b21760 G1_func_00b21760;
void func_00b21760()
{
    G1_func_00b21760.m();
}
