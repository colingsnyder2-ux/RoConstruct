// roc 2012-06 00b17420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17420
//
// 00b17420  b92818e300           mov ecx, 0xe31828
// 00b17425  e9c6aaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17420 { void m(); };
extern T_func_00b17420 G1_func_00b17420;
void func_00b17420()
{
    G1_func_00b17420.m();
}
