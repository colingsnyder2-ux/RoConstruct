// roc 2012-06 00b139b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b139b0
//
// 00b139b0  a1d023e200           mov eax, dword ptr [0xe223d0]
// 00b139b5  50                   push eax
// 00b139b6  e859e7e6ff           call 0x982114
// 00b139bb  83c404               add esp, 4
// 00b139be  c705a823e2002c3cb400 mov dword ptr [0xe223a8], 0xb43c2c
// 00b139c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b139b0(int);
void func_00b139b0()
{
    G4_func_00b139b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
