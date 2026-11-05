// roc 2012-06 00b15220  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15220
//
// 00b15220  a1909ee200           mov eax, dword ptr [0xe29e90]
// 00b15225  50                   push eax
// 00b15226  e8e9cee6ff           call 0x982114
// 00b1522b  83c404               add esp, 4
// 00b1522e  c705649ee2002c3cb400 mov dword ptr [0xe29e64], 0xb43c2c
// 00b15238  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15220(int);
void func_00b15220()
{
    G4_func_00b15220(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
