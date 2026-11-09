// roc 2012-06 00b1f000  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f000
//
// 00b1f000  a14021e500           mov eax, dword ptr [0xe52140]
// 00b1f005  50                   push eax
// 00b1f006  e80931e6ff           call 0x982114
// 00b1f00b  83c404               add esp, 4
// 00b1f00e  c7051821e5002c3cb400 mov dword ptr [0xe52118], 0xb43c2c
// 00b1f018  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f000(int);
void func_00b1f000()
{
    G4_func_00b1f000(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
