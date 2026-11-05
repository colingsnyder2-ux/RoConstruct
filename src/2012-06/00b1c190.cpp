// roc 2012-06 00b1c190  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c190
//
// 00b1c190  a17cabe400           mov eax, dword ptr [0xe4ab7c]
// 00b1c195  50                   push eax
// 00b1c196  e8795fe6ff           call 0x982114
// 00b1c19b  83c404               add esp, 4
// 00b1c19e  c70554abe4002c3cb400 mov dword ptr [0xe4ab54], 0xb43c2c
// 00b1c1a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c190(int);
void func_00b1c190()
{
    G4_func_00b1c190(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
