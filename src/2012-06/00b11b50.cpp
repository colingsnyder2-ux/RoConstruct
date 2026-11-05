// roc 2012-06 00b11b50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b50
//
// 00b11b50  b97089e100           mov ecx, 0xe18970
// 00b11b55  e9e6c492ff           jmp 0x43e040
// auto-matched from its assembly shape

struct T_func_00b11b50 { void m(); };
extern T_func_00b11b50 G1_func_00b11b50;
void func_00b11b50()
{
    G1_func_00b11b50.m();
}
