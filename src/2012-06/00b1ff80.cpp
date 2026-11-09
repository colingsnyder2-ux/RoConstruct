// roc 2012-06 00b1ff80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ff80
//
// 00b1ff80  a1544ce500           mov eax, dword ptr [0xe54c54]
// 00b1ff85  50                   push eax
// 00b1ff86  e88921e6ff           call 0x982114
// 00b1ff8b  83c404               add esp, 4
// 00b1ff8e  c7052c4ce5002c3cb400 mov dword ptr [0xe54c2c], 0xb43c2c
// 00b1ff98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ff80(int);
void func_00b1ff80()
{
    G4_func_00b1ff80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
