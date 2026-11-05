// roc 2012-06 00b15bd0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15bd0
//
// 00b15bd0  a180b2e200           mov eax, dword ptr [0xe2b280]
// 00b15bd5  50                   push eax
// 00b15bd6  e839c5e6ff           call 0x982114
// 00b15bdb  83c404               add esp, 4
// 00b15bde  c70554b2e2002c3cb400 mov dword ptr [0xe2b254], 0xb43c2c
// 00b15be8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15bd0(int);
void func_00b15bd0()
{
    G4_func_00b15bd0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
