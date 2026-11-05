// roc 2012-06 00b179b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b179b0
//
// 00b179b0  a13c2ee300           mov eax, dword ptr [0xe32e3c]
// 00b179b5  50                   push eax
// 00b179b6  e859a7e6ff           call 0x982114
// 00b179bb  83c404               add esp, 4
// 00b179be  c705142ee3002c3cb400 mov dword ptr [0xe32e14], 0xb43c2c
// 00b179c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b179b0(int);
void func_00b179b0()
{
    G4_func_00b179b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
