// roc 2012-06 00b18630  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18630
//
// 00b18630  a1185fe300           mov eax, dword ptr [0xe35f18]
// 00b18635  50                   push eax
// 00b18636  e8d99ae6ff           call 0x982114
// 00b1863b  83c404               add esp, 4
// 00b1863e  c705f05ee3002c3cb400 mov dword ptr [0xe35ef0], 0xb43c2c
// 00b18648  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18630(int);
void func_00b18630()
{
    G4_func_00b18630(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
