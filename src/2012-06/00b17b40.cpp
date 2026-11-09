// roc 2012-06 00b17b40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17b40
//
// 00b17b40  a10c32e300           mov eax, dword ptr [0xe3320c]
// 00b17b45  50                   push eax
// 00b17b46  e8c9a5e6ff           call 0x982114
// 00b17b4b  83c404               add esp, 4
// 00b17b4e  c705e431e3002c3cb400 mov dword ptr [0xe331e4], 0xb43c2c
// 00b17b58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17b40(int);
void func_00b17b40()
{
    G4_func_00b17b40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
