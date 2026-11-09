// roc 2012-06 00b1e860  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e860
//
// 00b1e860  a1b80fe500           mov eax, dword ptr [0xe50fb8]
// 00b1e865  50                   push eax
// 00b1e866  e8a938e6ff           call 0x982114
// 00b1e86b  83c404               add esp, 4
// 00b1e86e  c705900fe5002c3cb400 mov dword ptr [0xe50f90], 0xb43c2c
// 00b1e878  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e860(int);
void func_00b1e860()
{
    G4_func_00b1e860(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
