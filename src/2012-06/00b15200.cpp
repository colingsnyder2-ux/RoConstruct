// roc 2012-06 00b15200  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15200
//
// 00b15200  a1e899e200           mov eax, dword ptr [0xe299e8]
// 00b15205  50                   push eax
// 00b15206  e809cfe6ff           call 0x982114
// 00b1520b  83c404               add esp, 4
// 00b1520e  c705c099e2002c3cb400 mov dword ptr [0xe299c0], 0xb43c2c
// 00b15218  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15200(int);
void func_00b15200()
{
    G4_func_00b15200(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
