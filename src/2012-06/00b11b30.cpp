// roc 2012-06 00b11b30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b30
//
// 00b11b30  b96889e100           mov ecx, 0xe18968
// 00b11b35  e926cd92ff           jmp 0x43e860
// auto-matched from its assembly shape

struct T_func_00b11b30 { void m(); };
extern T_func_00b11b30 G1_func_00b11b30;
void func_00b11b30()
{
    G1_func_00b11b30.m();
}
