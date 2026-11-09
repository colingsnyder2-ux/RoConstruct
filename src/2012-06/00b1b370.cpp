// roc 2012-06 00b1b370  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b370
//
// 00b1b370  b9109be300           mov ecx, 0xe39b10
// 00b1b375  e9f6458fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b370 { void m(); };
extern T_func_00b1b370 G1_func_00b1b370;
void func_00b1b370()
{
    G1_func_00b1b370.m();
}
