// roc 2012-06 00b1b970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b970
//
// 00b1b970  b90092e400           mov ecx, 0xe49200
// 00b1b975  e97665a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b970 { void m(); };
extern T_func_00b1b970 G1_func_00b1b970;
void func_00b1b970()
{
    G1_func_00b1b970.m();
}
