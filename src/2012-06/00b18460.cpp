// roc 2012-06 00b18460  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18460
//
// 00b18460  b94058e300           mov ecx, 0xe35840
// 00b18465  e9869aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18460 { void m(); };
extern T_func_00b18460 G1_func_00b18460;
void func_00b18460()
{
    G1_func_00b18460.m();
}
