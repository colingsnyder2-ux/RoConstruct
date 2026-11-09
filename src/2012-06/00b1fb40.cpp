// roc 2012-06 00b1fb40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fb40
//
// 00b1fb40  b99838e500           mov ecx, 0xe53898
// 00b1fb45  e9f6fed5ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1fb40 { void m(); };
extern T_func_00b1fb40 G1_func_00b1fb40;
void func_00b1fb40()
{
    G1_func_00b1fb40.m();
}
