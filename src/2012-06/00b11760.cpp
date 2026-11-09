// roc 2012-06 00b11760  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11760
//
// 00b11760  b9cc7ce100           mov ecx, 0xe17ccc
// 00b11765  e906f88fff           jmp 0x410f70
// auto-matched from its assembly shape

struct T_func_00b11760 { void m(); };
extern T_func_00b11760 G1_func_00b11760;
void func_00b11760()
{
    G1_func_00b11760.m();
}
