// roc 2012-06 00b21770  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21770
//
// 00b21770  b9089ce500           mov ecx, 0xe59c08
// 00b21775  e946c3ecff           jmp 0x9edac0
// auto-matched from its assembly shape

struct T_func_00b21770 { void m(); };
extern T_func_00b21770 G1_func_00b21770;
void func_00b21770()
{
    G1_func_00b21770.m();
}
