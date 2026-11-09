// roc 2012-06 00b20c60  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20c60
//
// 00b20c60  b9b85fe500           mov ecx, 0xe55fb8
// 00b20c65  e996c9dcff           jmp 0x8ed600
// auto-matched from its assembly shape

struct T_func_00b20c60 { void m(); };
extern T_func_00b20c60 G1_func_00b20c60;
void func_00b20c60()
{
    G1_func_00b20c60.m();
}
