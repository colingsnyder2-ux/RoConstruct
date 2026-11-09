// roc 2012-06 00b1f480  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f480
//
// 00b1f480  a1482ae500           mov eax, dword ptr [0xe52a48]
// 00b1f485  50                   push eax
// 00b1f486  e8892ce6ff           call 0x982114
// 00b1f48b  83c404               add esp, 4
// 00b1f48e  c7051c2ae5002c3cb400 mov dword ptr [0xe52a1c], 0xb43c2c
// 00b1f498  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f480(int);
void func_00b1f480()
{
    G4_func_00b1f480(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
