// roc 2012-06 00b18450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18450
//
// 00b18450  b9c057e300           mov ecx, 0xe357c0
// 00b18455  e9e675d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b18450 { void m(); };
extern T_func_00b18450 G1_func_00b18450;
void func_00b18450()
{
    G1_func_00b18450.m();
}
