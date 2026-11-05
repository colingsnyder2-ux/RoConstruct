// roc 2012-06 00b206f0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b206f0
//
// 00b206f0  a1b857e500           mov eax, dword ptr [0xe557b8]
// 00b206f5  50                   push eax
// 00b206f6  e8191ae6ff           call 0x982114
// 00b206fb  83c404               add esp, 4
// 00b206fe  c7058c57e5002c3cb400 mov dword ptr [0xe5578c], 0xb43c2c
// 00b20708  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b206f0(int);
void func_00b206f0()
{
    G4_func_00b206f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
