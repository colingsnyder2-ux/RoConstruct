// roc 2012-06 00b15320  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15320
//
// 00b15320  a1909be200           mov eax, dword ptr [0xe29b90]
// 00b15325  50                   push eax
// 00b15326  e8e9cde6ff           call 0x982114
// 00b1532b  83c404               add esp, 4
// 00b1532e  c705649be2002c3cb400 mov dword ptr [0xe29b64], 0xb43c2c
// 00b15338  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15320(int);
void func_00b15320()
{
    G4_func_00b15320(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
