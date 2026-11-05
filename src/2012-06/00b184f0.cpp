// roc 2012-06 00b184f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b184f0
//
// 00b184f0  a1f060e300           mov eax, dword ptr [0xe360f0]
// 00b184f5  50                   push eax
// 00b184f6  e8199ce6ff           call 0x982114
// 00b184fb  83c404               add esp, 4
// 00b184fe  c705c860e3002c3cb400 mov dword ptr [0xe360c8], 0xb43c2c
// 00b18508  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b184f0(int);
void func_00b184f0()
{
    G4_func_00b184f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
