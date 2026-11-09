// roc 2012-06 00b105a0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b105a0
//
// 00b105a0  685016b200           push 0xb21650
// 00b105a5  e84b2ce7ff           call 0x9831f5
// 00b105aa  59                   pop ecx
// 00b105ab  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b105a0;
extern void G1_func_00b105a0(void*);
void func_00b105a0()
{
    G1_func_00b105a0(&G2_func_00b105a0);
}
