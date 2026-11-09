// roc 2012-06 00b16380  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16380
//
// 00b16380  b9b8dae200           mov ecx, 0xe2dab8
// 00b16385  e9e63cb9ff           jmp 0x6aa070
// auto-matched from its assembly shape

struct T_func_00b16380 { void m(); };
extern T_func_00b16380 G1_func_00b16380;
void func_00b16380()
{
    G1_func_00b16380.m();
}
