// roc 2012-06 00b1e710  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e710
//
// 00b1e710  a1c809e500           mov eax, dword ptr [0xe509c8]
// 00b1e715  50                   push eax
// 00b1e716  e8f939e6ff           call 0x982114
// 00b1e71b  83c404               add esp, 4
// 00b1e71e  c705a009e5002c3cb400 mov dword ptr [0xe509a0], 0xb43c2c
// 00b1e728  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e710(int);
void func_00b1e710()
{
    G4_func_00b1e710(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
