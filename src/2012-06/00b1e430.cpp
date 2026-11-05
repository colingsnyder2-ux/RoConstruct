// roc 2012-06 00b1e430  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e430
//
// 00b1e430  a17004e500           mov eax, dword ptr [0xe50470]
// 00b1e435  50                   push eax
// 00b1e436  e8d93ce6ff           call 0x982114
// 00b1e43b  83c404               add esp, 4
// 00b1e43e  c7054804e5002c3cb400 mov dword ptr [0xe50448], 0xb43c2c
// 00b1e448  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e430(int);
void func_00b1e430()
{
    G4_func_00b1e430(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
