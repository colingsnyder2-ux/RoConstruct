// roc 2012-06 00aebac0  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aebac0
//
// 00aebac0  68702bb100           push 0xb12b70
// 00aebac5  e82b77e9ff           call 0x9831f5
// 00aebaca  59                   pop ecx
// 00aebacb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00aebac0;
extern void G1_func_00aebac0(void*);
void func_00aebac0()
{
    G1_func_00aebac0(&G2_func_00aebac0);
}
