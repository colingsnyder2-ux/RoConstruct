// roc 2012-06 00b11ba0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ba0
//
// 00b11ba0  b9188ae100           mov ecx, 0xe18a18
// 00b11ba5  e9f6b294ff           jmp 0x45cea0
// auto-matched from its assembly shape

struct T_func_00b11ba0 { void m(); };
extern T_func_00b11ba0 G1_func_00b11ba0;
void func_00b11ba0()
{
    G1_func_00b11ba0.m();
}
