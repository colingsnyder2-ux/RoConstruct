// roc 2012-06 00b1ef30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef30
//
// 00b1ef30  b9781be500           mov ecx, 0xe51b78
// 00b1ef35  e93622b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1ef30 { void m(); };
extern T_func_00b1ef30 G1_func_00b1ef30;
void func_00b1ef30()
{
    G1_func_00b1ef30.m();
}
