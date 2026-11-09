// roc 2012-06 00b21520  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21520
//
// 00b21520  b92c81e500           mov ecx, 0xe5812c
// 00b21525  e9e61abbff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b21520 { void m(); };
extern T_func_00b21520 G1_func_00b21520;
void func_00b21520()
{
    G1_func_00b21520.m();
}
