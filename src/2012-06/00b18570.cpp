// roc 2012-06 00b18570  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18570
//
// 00b18570  a1b860e300           mov eax, dword ptr [0xe360b8]
// 00b18575  50                   push eax
// 00b18576  e8999be6ff           call 0x982114
// 00b1857b  83c404               add esp, 4
// 00b1857e  c7058c60e3002c3cb400 mov dword ptr [0xe3608c], 0xb43c2c
// 00b18588  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18570(int);
void func_00b18570()
{
    G4_func_00b18570(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
