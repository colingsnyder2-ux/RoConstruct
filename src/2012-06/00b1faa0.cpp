// roc 2012-06 00b1faa0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1faa0
//
// 00b1faa0  a12436e500           mov eax, dword ptr [0xe53624]
// 00b1faa5  50                   push eax
// 00b1faa6  e86926e6ff           call 0x982114
// 00b1faab  83c404               add esp, 4
// 00b1faae  c705fc35e5002c3cb400 mov dword ptr [0xe535fc], 0xb43c2c
// 00b1fab8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1faa0(int);
void func_00b1faa0()
{
    G4_func_00b1faa0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
