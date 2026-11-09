// roc 2012-06 00b13190  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13190
//
// 00b13190  a1ec08e200           mov eax, dword ptr [0xe208ec]
// 00b13195  50                   push eax
// 00b13196  e879efe6ff           call 0x982114
// 00b1319b  83c404               add esp, 4
// 00b1319e  c705c408e2002c3cb400 mov dword ptr [0xe208c4], 0xb43c2c
// 00b131a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13190(int);
void func_00b13190()
{
    G4_func_00b13190(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
