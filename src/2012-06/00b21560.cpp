// roc 2012-06 00b21560  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21560
//
// 00b21560  b9cc8be500           mov ecx, 0xe58bcc
// 00b21565  e9a61abbff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b21560 { void m(); };
extern T_func_00b21560 G1_func_00b21560;
void func_00b21560()
{
    G1_func_00b21560.m();
}
