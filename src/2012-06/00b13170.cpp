// roc 2012-06 00b13170  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13170
//
// 00b13170  a11012e200           mov eax, dword ptr [0xe21210]
// 00b13175  50                   push eax
// 00b13176  e899efe6ff           call 0x982114
// 00b1317b  83c404               add esp, 4
// 00b1317e  c705e811e2002c3cb400 mov dword ptr [0xe211e8], 0xb43c2c
// 00b13188  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13170(int);
void func_00b13170()
{
    G4_func_00b13170(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
