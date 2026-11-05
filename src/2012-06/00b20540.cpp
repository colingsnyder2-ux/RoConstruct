// roc 2012-06 00b20540  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20540
//
// 00b20540  a13855e500           mov eax, dword ptr [0xe55538]
// 00b20545  50                   push eax
// 00b20546  e8c91be6ff           call 0x982114
// 00b2054b  83c404               add esp, 4
// 00b2054e  c7051055e5002c3cb400 mov dword ptr [0xe55510], 0xb43c2c
// 00b20558  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20540(int);
void func_00b20540()
{
    G4_func_00b20540(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
