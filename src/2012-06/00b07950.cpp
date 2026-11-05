// roc 2012-06 00b07950  unit: seg_00b00000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b07950
//
// 00b07950  6880deb100           push 0xb1de80
// 00b07955  e89bb8e7ff           call 0x9831f5
// 00b0795a  59                   pop ecx
// 00b0795b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b07950;
extern void G1_func_00b07950(void*);
void func_00b07950()
{
    G1_func_00b07950(&G2_func_00b07950);
}
