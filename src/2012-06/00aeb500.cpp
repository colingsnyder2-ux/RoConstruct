// roc 2012-06 00aeb500  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb500
//
// 00aeb500  68e026b100           push 0xb126e0
// 00aeb505  e8eb7ce9ff           call 0x9831f5
// 00aeb50a  59                   pop ecx
// 00aeb50b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00aeb500;
extern void G1_func_00aeb500(void*);
void func_00aeb500()
{
    G1_func_00aeb500(&G2_func_00aeb500);
}
