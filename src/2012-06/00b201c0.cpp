// roc 2012-06 00b201c0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b201c0
//
// 00b201c0  a1704be500           mov eax, dword ptr [0xe54b70]
// 00b201c5  50                   push eax
// 00b201c6  e8491fe6ff           call 0x982114
// 00b201cb  83c404               add esp, 4
// 00b201ce  c705484be5002c3cb400 mov dword ptr [0xe54b48], 0xb43c2c
// 00b201d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b201c0(int);
void func_00b201c0()
{
    G4_func_00b201c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
