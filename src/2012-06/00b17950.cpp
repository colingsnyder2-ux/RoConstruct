// roc 2012-06 00b17950  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17950
//
// 00b17950  a10c2ee300           mov eax, dword ptr [0xe32e0c]
// 00b17955  50                   push eax
// 00b17956  e8b9a7e6ff           call 0x982114
// 00b1795b  83c404               add esp, 4
// 00b1795e  c705e42de3002c3cb400 mov dword ptr [0xe32de4], 0xb43c2c
// 00b17968  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17950(int);
void func_00b17950()
{
    G4_func_00b17950(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
