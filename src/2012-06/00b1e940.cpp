// roc 2012-06 00b1e940  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e940
//
// 00b1e940  a1140de500           mov eax, dword ptr [0xe50d14]
// 00b1e945  50                   push eax
// 00b1e946  e8c937e6ff           call 0x982114
// 00b1e94b  83c404               add esp, 4
// 00b1e94e  c705e80ce5002c3cb400 mov dword ptr [0xe50ce8], 0xb43c2c
// 00b1e958  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e940(int);
void func_00b1e940()
{
    G4_func_00b1e940(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
