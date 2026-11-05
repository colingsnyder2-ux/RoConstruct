// roc 2012-06 00b20710  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20710
//
// 00b20710  a1e857e500           mov eax, dword ptr [0xe557e8]
// 00b20715  50                   push eax
// 00b20716  e8f919e6ff           call 0x982114
// 00b2071b  83c404               add esp, 4
// 00b2071e  c705bc57e5002c3cb400 mov dword ptr [0xe557bc], 0xb43c2c
// 00b20728  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20710(int);
void func_00b20710()
{
    G4_func_00b20710(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
