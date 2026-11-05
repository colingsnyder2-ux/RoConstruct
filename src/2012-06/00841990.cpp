// roc 2012-06 00841990  unit: seg_00840000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00841990
//
// 00841990  6878a2e100           push 0xe1a278
// 00841995  e8c6a81300           call 0x97c260
// 0084199a  59                   pop ecx
// 0084199b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00841990;
extern void G1_func_00841990(void*);
void func_00841990()
{
    G1_func_00841990(&G2_func_00841990);
}
