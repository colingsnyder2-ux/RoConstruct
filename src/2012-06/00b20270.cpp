// roc 2012-06 00b20270  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20270
//
// 00b20270  b9e83de500           mov ecx, 0xe53de8
// 00b20275  e9f6f68eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20270 { void m(); };
extern T_func_00b20270 G1_func_00b20270;
void func_00b20270()
{
    G1_func_00b20270.m();
}
