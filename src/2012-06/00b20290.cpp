// roc 2012-06 00b20290  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20290
//
// 00b20290  b9004fe500           mov ecx, 0xe54f00
// 00b20295  e9561ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20290 { void m(); };
extern T_func_00b20290 G1_func_00b20290;
void func_00b20290()
{
    G1_func_00b20290.m();
}
