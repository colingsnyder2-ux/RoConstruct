// roc 2012-06 00b13f30  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13f30
//
// 00b13f30  a1bc38e200           mov eax, dword ptr [0xe238bc]
// 00b13f35  50                   push eax
// 00b13f36  e8d9e1e6ff           call 0x982114
// 00b13f3b  83c404               add esp, 4
// 00b13f3e  c7059438e2002c3cb400 mov dword ptr [0xe23894], 0xb43c2c
// 00b13f48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13f30(int);
void func_00b13f30()
{
    G4_func_00b13f30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
