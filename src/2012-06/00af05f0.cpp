// roc 2012-06 00af05f0  unit: seg_00af0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af05f0
//
// 00af05f0  68e049b100           push 0xb149e0
// 00af05f5  e8fb2be9ff           call 0x9831f5
// 00af05fa  59                   pop ecx
// 00af05fb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00af05f0;
extern void G1_func_00af05f0(void*);
void func_00af05f0()
{
    G1_func_00af05f0(&G2_func_00af05f0);
}
