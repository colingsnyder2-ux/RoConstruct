// roc 2012-06 00b1f680  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f680
//
// 00b1f680  a1a42de500           mov eax, dword ptr [0xe52da4]
// 00b1f685  50                   push eax
// 00b1f686  e8892ae6ff           call 0x982114
// 00b1f68b  83c404               add esp, 4
// 00b1f68e  c7057c2de5002c3cb400 mov dword ptr [0xe52d7c], 0xb43c2c
// 00b1f698  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f680(int);
void func_00b1f680()
{
    G4_func_00b1f680(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
