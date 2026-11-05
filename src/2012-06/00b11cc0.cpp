// roc 2012-06 00b11cc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11cc0
//
// 00b11cc0  a1b88ce100           mov eax, dword ptr [0xe18cb8]
// 00b11cc5  50                   push eax
// 00b11cc6  e84904e7ff           call 0x982114
// 00b11ccb  83c404               add esp, 4
// 00b11cce  c705908ce1002c3cb400 mov dword ptr [0xe18c90], 0xb43c2c
// 00b11cd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11cc0(int);
void func_00b11cc0()
{
    G4_func_00b11cc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
