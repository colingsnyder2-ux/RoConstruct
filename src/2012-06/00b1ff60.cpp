// roc 2012-06 00b1ff60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ff60
//
// 00b1ff60  a1e449e500           mov eax, dword ptr [0xe549e4]
// 00b1ff65  50                   push eax
// 00b1ff66  e8a921e6ff           call 0x982114
// 00b1ff6b  83c404               add esp, 4
// 00b1ff6e  c705bc49e5002c3cb400 mov dword ptr [0xe549bc], 0xb43c2c
// 00b1ff78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ff60(int);
void func_00b1ff60()
{
    G4_func_00b1ff60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
