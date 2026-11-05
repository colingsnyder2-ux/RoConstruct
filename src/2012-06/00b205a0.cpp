// roc 2012-06 00b205a0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b205a0
//
// 00b205a0  a1d454e500           mov eax, dword ptr [0xe554d4]
// 00b205a5  50                   push eax
// 00b205a6  e8691be6ff           call 0x982114
// 00b205ab  83c404               add esp, 4
// 00b205ae  c705ac54e5002c3cb400 mov dword ptr [0xe554ac], 0xb43c2c
// 00b205b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b205a0(int);
void func_00b205a0()
{
    G4_func_00b205a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
