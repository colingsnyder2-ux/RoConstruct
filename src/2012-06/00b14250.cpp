// roc 2012-06 00b14250  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14250
//
// 00b14250  a14039e200           mov eax, dword ptr [0xe23940]
// 00b14255  50                   push eax
// 00b14256  e8b9dee6ff           call 0x982114
// 00b1425b  83c404               add esp, 4
// 00b1425e  c7051839e2002c3cb400 mov dword ptr [0xe23918], 0xb43c2c
// 00b14268  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14250(int);
void func_00b14250()
{
    G4_func_00b14250(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
