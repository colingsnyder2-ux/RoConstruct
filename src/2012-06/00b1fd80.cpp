// roc 2012-06 00b1fd80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fd80
//
// 00b1fd80  b9a83ae500           mov ecx, 0xe53aa8
// 00b1fd85  e98688daff           jmp 0x8c8610
// auto-matched from its assembly shape

struct T_func_00b1fd80 { void m(); };
extern T_func_00b1fd80 G1_func_00b1fd80;
void func_00b1fd80()
{
    G1_func_00b1fd80.m();
}
