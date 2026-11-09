// roc 2012-06 00b14d40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14d40
//
// 00b14d40  a1449fe200           mov eax, dword ptr [0xe29f44]
// 00b14d45  50                   push eax
// 00b14d46  e8c9d3e6ff           call 0x982114
// 00b14d4b  83c404               add esp, 4
// 00b14d4e  c7051c9fe2002c3cb400 mov dword ptr [0xe29f1c], 0xb43c2c
// 00b14d58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14d40(int);
void func_00b14d40()
{
    G4_func_00b14d40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
