// roc 2012-06 00b18680  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18680
//
// 00b18680  a1045de300           mov eax, dword ptr [0xe35d04]
// 00b18685  50                   push eax
// 00b18686  e8899ae6ff           call 0x982114
// 00b1868b  83c404               add esp, 4
// 00b1868e  c705dc5ce3002c3cb400 mov dword ptr [0xe35cdc], 0xb43c2c
// 00b18698  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18680(int);
void func_00b18680()
{
    G4_func_00b18680(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
