// roc 2012-06 00b18590  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18590
//
// 00b18590  a12460e300           mov eax, dword ptr [0xe36024]
// 00b18595  50                   push eax
// 00b18596  e8799be6ff           call 0x982114
// 00b1859b  83c404               add esp, 4
// 00b1859e  c705fc5fe3002c3cb400 mov dword ptr [0xe35ffc], 0xb43c2c
// 00b185a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18590(int);
void func_00b18590()
{
    G4_func_00b18590(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
