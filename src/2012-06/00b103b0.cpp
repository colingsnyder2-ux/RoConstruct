// roc 2012-06 00b103b0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b103b0
//
// 00b103b0  68f014b200           push 0xb214f0
// 00b103b5  e83b2ee7ff           call 0x9831f5
// 00b103ba  59                   pop ecx
// 00b103bb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b103b0;
extern void G1_func_00b103b0(void*);
void func_00b103b0()
{
    G1_func_00b103b0(&G2_func_00b103b0);
}
