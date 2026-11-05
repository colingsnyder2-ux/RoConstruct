// roc 2012-06 00b11ce0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ce0
//
// 00b11ce0  a18c8ce100           mov eax, dword ptr [0xe18c8c]
// 00b11ce5  50                   push eax
// 00b11ce6  e82904e7ff           call 0x982114
// 00b11ceb  83c404               add esp, 4
// 00b11cee  c705648ce1002c3cb400 mov dword ptr [0xe18c64], 0xb43c2c
// 00b11cf8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11ce0(int);
void func_00b11ce0()
{
    G4_func_00b11ce0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
