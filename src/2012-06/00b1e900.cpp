// roc 2012-06 00b1e900  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e900
//
// 00b1e900  a1700de500           mov eax, dword ptr [0xe50d70]
// 00b1e905  50                   push eax
// 00b1e906  e80938e6ff           call 0x982114
// 00b1e90b  83c404               add esp, 4
// 00b1e90e  c705480de5002c3cb400 mov dword ptr [0xe50d48], 0xb43c2c
// 00b1e918  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e900(int);
void func_00b1e900()
{
    G4_func_00b1e900(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
