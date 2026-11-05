// roc 2012-06 00b151c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b151c0
//
// 00b151c0  a1789de200           mov eax, dword ptr [0xe29d78]
// 00b151c5  50                   push eax
// 00b151c6  e849cfe6ff           call 0x982114
// 00b151cb  83c404               add esp, 4
// 00b151ce  c705509de2002c3cb400 mov dword ptr [0xe29d50], 0xb43c2c
// 00b151d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b151c0(int);
void func_00b151c0()
{
    G4_func_00b151c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
