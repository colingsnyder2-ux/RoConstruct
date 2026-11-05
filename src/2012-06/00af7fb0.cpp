// roc 2012-06 00af7fb0  unit: seg_00af0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af7fb0
//
// 00af7fb0  685076b100           push 0xb17650
// 00af7fb5  e83bb2e8ff           call 0x9831f5
// 00af7fba  59                   pop ecx
// 00af7fbb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00af7fb0;
extern void G1_func_00af7fb0(void*);
void func_00af7fb0()
{
    G1_func_00af7fb0(&G2_func_00af7fb0);
}
