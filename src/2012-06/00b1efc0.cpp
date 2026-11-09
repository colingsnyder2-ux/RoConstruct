// roc 2012-06 00b1efc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1efc0
//
// 00b1efc0  b9801de500           mov ecx, 0xe51d80
// 00b1efc5  e9760ad6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1efc0 { void m(); };
extern T_func_00b1efc0 G1_func_00b1efc0;
void func_00b1efc0()
{
    G1_func_00b1efc0.m();
}
