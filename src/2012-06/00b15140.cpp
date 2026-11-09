// roc 2012-06 00b15140  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15140
//
// 00b15140  a14c9de200           mov eax, dword ptr [0xe29d4c]
// 00b15145  50                   push eax
// 00b15146  e8c9cfe6ff           call 0x982114
// 00b1514b  83c404               add esp, 4
// 00b1514e  c705249de2002c3cb400 mov dword ptr [0xe29d24], 0xb43c2c
// 00b15158  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15140(int);
void func_00b15140()
{
    G4_func_00b15140(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
