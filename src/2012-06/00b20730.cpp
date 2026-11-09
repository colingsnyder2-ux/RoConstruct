// roc 2012-06 00b20730  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20730
//
// 00b20730  a11458e500           mov eax, dword ptr [0xe55814]
// 00b20735  50                   push eax
// 00b20736  e8d919e6ff           call 0x982114
// 00b2073b  83c404               add esp, 4
// 00b2073e  c705ec57e5002c3cb400 mov dword ptr [0xe557ec], 0xb43c2c
// 00b20748  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20730(int);
void func_00b20730()
{
    G4_func_00b20730(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
