// roc 2012-06 00b20280  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20280
//
// 00b20280  b9003ce500           mov ecx, 0xe53c00
// 00b20285  e9e6f68eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20280 { void m(); };
extern T_func_00b20280 G1_func_00b20280;
void func_00b20280()
{
    G1_func_00b20280.m();
}
