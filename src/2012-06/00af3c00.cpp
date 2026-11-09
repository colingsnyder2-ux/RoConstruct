// roc 2012-06 00af3c00  unit: seg_00af0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af3c00
//
// 00af3c00  687cffb800           push 0xb8ff7c
// 00af3c05  e8d6b6b8ff           call 0x67f2e0
// 00af3c0a  83c404               add esp, 4
// 00af3c0d  a308b4e200           mov dword ptr [0xe2b408], eax
// 00af3c12  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G3_OBJ;
extern int* G1_VALUE;
extern int __cdecl G2_func_00af3c00(void*);
void func_00af3c00()
{
    G1_VALUE = (int*)G2_func_00af3c00(&G3_OBJ);
}
