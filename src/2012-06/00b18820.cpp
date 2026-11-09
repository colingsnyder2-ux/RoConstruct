// roc 2012-06 00b18820  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18820
//
// 00b18820  b9705ce300           mov ecx, 0xe35c70
// 00b18825  e9c696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18820 { void m(); };
extern T_func_00b18820 G1_func_00b18820;
void func_00b18820()
{
    G1_func_00b18820.m();
}
