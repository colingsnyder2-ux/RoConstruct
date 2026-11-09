// roc 2012-06 00b1b260  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b260
//
// 00b1b260  b978bbe300           mov ecx, 0xe3bb78
// 00b1b265  e906478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b260 { void m(); };
extern T_func_00b1b260 G1_func_00b1b260;
void func_00b1b260()
{
    G1_func_00b1b260.m();
}
