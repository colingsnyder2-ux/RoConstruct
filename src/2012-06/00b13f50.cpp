// roc 2012-06 00b13f50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13f50
//
// 00b13f50  a15c37e200           mov eax, dword ptr [0xe2375c]
// 00b13f55  50                   push eax
// 00b13f56  e8b9e1e6ff           call 0x982114
// 00b13f5b  83c404               add esp, 4
// 00b13f5e  c7053437e2002c3cb400 mov dword ptr [0xe23734], 0xb43c2c
// 00b13f68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13f50(int);
void func_00b13f50()
{
    G4_func_00b13f50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
