// roc 2012-06 00af0600  unit: seg_00af0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0600
//
// 00af0600  68004ab100           push 0xb14a00
// 00af0605  e8eb2be9ff           call 0x9831f5
// 00af060a  59                   pop ecx
// 00af060b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00af0600;
extern void G1_func_00af0600(void*);
void func_00af0600()
{
    G1_func_00af0600(&G2_func_00af0600);
}
