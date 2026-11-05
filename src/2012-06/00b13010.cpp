// roc 2012-06 00b13010  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13010
//
// 00b13010  a1e413e200           mov eax, dword ptr [0xe213e4]
// 00b13015  50                   push eax
// 00b13016  e8f9f0e6ff           call 0x982114
// 00b1301b  83c404               add esp, 4
// 00b1301e  c705b813e2002c3cb400 mov dword ptr [0xe213b8], 0xb43c2c
// 00b13028  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13010(int);
void func_00b13010()
{
    G4_func_00b13010(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
