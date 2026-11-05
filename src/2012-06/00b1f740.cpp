// roc 2012-06 00b1f740  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f740
//
// 00b1f740  a1702ce500           mov eax, dword ptr [0xe52c70]
// 00b1f745  50                   push eax
// 00b1f746  e8c929e6ff           call 0x982114
// 00b1f74b  83c404               add esp, 4
// 00b1f74e  c705482ce5002c3cb400 mov dword ptr [0xe52c48], 0xb43c2c
// 00b1f758  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f740(int);
void func_00b1f740()
{
    G4_func_00b1f740(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
