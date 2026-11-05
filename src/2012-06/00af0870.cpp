// roc 2012-06 00af0870  unit: seg_00af0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0870
//
// 00af0870  68404cb100           push 0xb14c40
// 00af0875  e87b29e9ff           call 0x9831f5
// 00af087a  59                   pop ecx
// 00af087b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00af0870;
extern void G1_func_00af0870(void*);
void func_00af0870()
{
    G1_func_00af0870(&G2_func_00af0870);
}
