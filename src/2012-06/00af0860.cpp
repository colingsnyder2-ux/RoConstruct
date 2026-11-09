// roc 2012-06 00af0860  unit: seg_00af0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0860
//
// 00af0860  68f04bb100           push 0xb14bf0
// 00af0865  e88b29e9ff           call 0x9831f5
// 00af086a  59                   pop ecx
// 00af086b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00af0860;
extern void G1_func_00af0860(void*);
void func_00af0860()
{
    G1_func_00af0860(&G2_func_00af0860);
}
