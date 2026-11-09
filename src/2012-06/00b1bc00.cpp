// roc 2012-06 00b1bc00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bc00
//
// 00b1bc00  a1f09ce400           mov eax, dword ptr [0xe49cf0]
// 00b1bc05  50                   push eax
// 00b1bc06  e80965e6ff           call 0x982114
// 00b1bc0b  83c404               add esp, 4
// 00b1bc0e  c705c89ce4002c3cb400 mov dword ptr [0xe49cc8], 0xb43c2c
// 00b1bc18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1bc00(int);
void func_00b1bc00()
{
    G4_func_00b1bc00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
