// roc 2012-06 00b1e190  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e190
//
// 00b1e190  a12002e500           mov eax, dword ptr [0xe50220]
// 00b1e195  50                   push eax
// 00b1e196  e8793fe6ff           call 0x982114
// 00b1e19b  83c404               add esp, 4
// 00b1e19e  c705f401e5002c3cb400 mov dword ptr [0xe501f4], 0xb43c2c
// 00b1e1a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e190(int);
void func_00b1e190()
{
    G4_func_00b1e190(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
