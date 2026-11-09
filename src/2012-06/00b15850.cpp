// roc 2012-06 00b15850  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15850
//
// 00b15850  a1a0a8e200           mov eax, dword ptr [0xe2a8a0]
// 00b15855  50                   push eax
// 00b15856  e8b9c8e6ff           call 0x982114
// 00b1585b  83c404               add esp, 4
// 00b1585e  c70578a8e2002c3cb400 mov dword ptr [0xe2a878], 0xb43c2c
// 00b15868  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15850(int);
void func_00b15850()
{
    G4_func_00b15850(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
