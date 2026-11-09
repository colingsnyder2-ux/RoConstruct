// roc 2012-06 00b10c30  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c30
//
// 00b10c30  685017b200           push 0xb21750
// 00b10c35  e8bb25e7ff           call 0x9831f5
// 00b10c3a  59                   pop ecx
// 00b10c3b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10c30;
extern void G1_func_00b10c30(void*);
void func_00b10c30()
{
    G1_func_00b10c30(&G2_func_00b10c30);
}
