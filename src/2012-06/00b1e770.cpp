// roc 2012-06 00b1e770  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e770
//
// 00b1e770  a1740ae500           mov eax, dword ptr [0xe50a74]
// 00b1e775  50                   push eax
// 00b1e776  e89939e6ff           call 0x982114
// 00b1e77b  83c404               add esp, 4
// 00b1e77e  c705480ae5002c3cb400 mov dword ptr [0xe50a48], 0xb43c2c
// 00b1e788  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e770(int);
void func_00b1e770()
{
    G4_func_00b1e770(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
