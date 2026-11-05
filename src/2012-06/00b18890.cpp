// roc 2012-06 00b18890  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18890
//
// 00b18890  b95861e300           mov ecx, 0xe36158
// 00b18895  e95696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18890 { void m(); };
extern T_func_00b18890 G1_func_00b18890;
void func_00b18890()
{
    G1_func_00b18890.m();
}
