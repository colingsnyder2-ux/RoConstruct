// roc 2012-06 00b13320  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13320
//
// 00b13320  b910fde100           mov ecx, 0xe1fd10
// 00b13325  e946c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13320 { void m(); };
extern T_func_00b13320 G1_func_00b13320;
void func_00b13320()
{
    G1_func_00b13320.m();
}
