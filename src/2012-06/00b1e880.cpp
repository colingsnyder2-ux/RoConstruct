// roc 2012-06 00b1e880  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e880
//
// 00b1e880  a1a80ee500           mov eax, dword ptr [0xe50ea8]
// 00b1e885  50                   push eax
// 00b1e886  e88938e6ff           call 0x982114
// 00b1e88b  83c404               add esp, 4
// 00b1e88e  c705800ee5002c3cb400 mov dword ptr [0xe50e80], 0xb43c2c
// 00b1e898  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e880(int);
void func_00b1e880()
{
    G4_func_00b1e880(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
