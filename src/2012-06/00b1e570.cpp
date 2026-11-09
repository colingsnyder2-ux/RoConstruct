// roc 2012-06 00b1e570  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e570
//
// 00b1e570  b98806e500           mov ecx, 0xe50688
// 00b1e575  e9f62bb6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1e570 { void m(); };
extern T_func_00b1e570 G1_func_00b1e570;
void func_00b1e570()
{
    G1_func_00b1e570.m();
}
