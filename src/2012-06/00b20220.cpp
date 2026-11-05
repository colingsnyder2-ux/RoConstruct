// roc 2012-06 00b20220  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20220
//
// 00b20220  b97047e500           mov ecx, 0xe54770
// 00b20225  e946f78eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20220 { void m(); };
extern T_func_00b20220 G1_func_00b20220;
void func_00b20220()
{
    G1_func_00b20220.m();
}
