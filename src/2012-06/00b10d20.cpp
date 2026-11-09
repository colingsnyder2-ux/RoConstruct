// roc 2012-06 00b10d20  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10d20
//
// 00b10d20  680018b200           push 0xb21800
// 00b10d25  e8cb24e7ff           call 0x9831f5
// 00b10d2a  59                   pop ecx
// 00b10d2b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10d20;
extern void G1_func_00b10d20(void*);
void func_00b10d20()
{
    G1_func_00b10d20(&G2_func_00b10d20);
}
