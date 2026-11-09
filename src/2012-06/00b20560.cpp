// roc 2012-06 00b20560  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20560
//
// 00b20560  a10454e500           mov eax, dword ptr [0xe55404]
// 00b20565  50                   push eax
// 00b20566  e8a91be6ff           call 0x982114
// 00b2056b  83c404               add esp, 4
// 00b2056e  c705dc53e5002c3cb400 mov dword ptr [0xe553dc], 0xb43c2c
// 00b20578  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20560(int);
void func_00b20560()
{
    G4_func_00b20560(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
