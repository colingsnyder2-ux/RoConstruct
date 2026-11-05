// roc 2012-06 00b11770  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11770
//
// 00b11770  b9d07ce100           mov ecx, 0xe17cd0
// 00b11775  e916f48fff           jmp 0x410b90
// auto-matched from its assembly shape

struct T_func_00b11770 { void m(); };
extern T_func_00b11770 G1_func_00b11770;
void func_00b11770()
{
    G1_func_00b11770.m();
}
