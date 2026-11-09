// roc 2012-06 00b1bb80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bb80
//
// 00b1bb80  a11c9fe400           mov eax, dword ptr [0xe49f1c]
// 00b1bb85  50                   push eax
// 00b1bb86  e88965e6ff           call 0x982114
// 00b1bb8b  83c404               add esp, 4
// 00b1bb8e  c705f09ee4002c3cb400 mov dword ptr [0xe49ef0], 0xb43c2c
// 00b1bb98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1bb80(int);
void func_00b1bb80()
{
    G4_func_00b1bb80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
