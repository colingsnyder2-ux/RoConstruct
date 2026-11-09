// roc 2012-06 00b17c20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17c20
//
// 00b17c20  a17439e300           mov eax, dword ptr [0xe33974]
// 00b17c25  50                   push eax
// 00b17c26  e8e9a4e6ff           call 0x982114
// 00b17c2b  83c404               add esp, 4
// 00b17c2e  c7054839e3002c3cb400 mov dword ptr [0xe33948], 0xb43c2c
// 00b17c38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17c20(int);
void func_00b17c20()
{
    G4_func_00b17c20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
