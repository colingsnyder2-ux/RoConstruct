// roc 2012-06 00b1ff20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ff20
//
// 00b1ff20  a1d04be500           mov eax, dword ptr [0xe54bd0]
// 00b1ff25  50                   push eax
// 00b1ff26  e8e921e6ff           call 0x982114
// 00b1ff2b  83c404               add esp, 4
// 00b1ff2e  c705a84be5002c3cb400 mov dword ptr [0xe54ba8], 0xb43c2c
// 00b1ff38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ff20(int);
void func_00b1ff20()
{
    G4_func_00b1ff20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
