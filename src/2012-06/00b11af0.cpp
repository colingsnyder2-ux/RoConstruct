// roc 2012-06 00b11af0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11af0
//
// 00b11af0  b95889e100           mov ecx, 0xe18958
// 00b11af5  e926df92ff           jmp 0x43fa20
// auto-matched from its assembly shape

struct T_func_00b11af0 { void m(); };
extern T_func_00b11af0 G1_func_00b11af0;
void func_00b11af0()
{
    G1_func_00b11af0.m();
}
