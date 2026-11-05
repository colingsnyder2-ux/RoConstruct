// roc 2012-06 00b1df70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1df70
//
// 00b1df70  a198fee400           mov eax, dword ptr [0xe4fe98]
// 00b1df75  50                   push eax
// 00b1df76  e89941e6ff           call 0x982114
// 00b1df7b  83c404               add esp, 4
// 00b1df7e  c7056cfee4002c3cb400 mov dword ptr [0xe4fe6c], 0xb43c2c
// 00b1df88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1df70(int);
void func_00b1df70()
{
    G4_func_00b1df70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
