// roc 2012-06 00b1fd90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fd90
//
// 00b1fd90  b9683ae500           mov ecx, 0xe53a68
// 00b1fd95  e95621a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fd90 { void m(); };
extern T_func_00b1fd90 G1_func_00b1fd90;
void func_00b1fd90()
{
    G1_func_00b1fd90.m();
}
