// roc 2012-06 00b21740  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21740
//
// 00b21740  b9d49be500           mov ecx, 0xe59bd4
// 00b21745  e9e629ebff           jmp 0x9d4130
// auto-matched from its assembly shape

struct T_func_00b21740 { void m(); };
extern T_func_00b21740 G1_func_00b21740;
void func_00b21740()
{
    G1_func_00b21740.m();
}
