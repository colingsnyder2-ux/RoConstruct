// roc 2012-06 00b11b40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b40
//
// 00b11b40  b96c89e100           mov ecx, 0xe1896c
// 00b11b45  e9c6c992ff           jmp 0x43e510
// auto-matched from its assembly shape

struct T_func_00b11b40 { void m(); };
extern T_func_00b11b40 G1_func_00b11b40;
void func_00b11b40()
{
    G1_func_00b11b40.m();
}
