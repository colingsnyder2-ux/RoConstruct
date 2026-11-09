// roc 2012-06 00b20240  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20240
//
// 00b20240  b9a043e500           mov ecx, 0xe543a0
// 00b20245  e926f78eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20240 { void m(); };
extern T_func_00b20240 G1_func_00b20240;
void func_00b20240()
{
    G1_func_00b20240.m();
}
