// roc 2012-06 00b18740  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18740
//
// 00b18740  a1445fe300           mov eax, dword ptr [0xe35f44]
// 00b18745  50                   push eax
// 00b18746  e8c999e6ff           call 0x982114
// 00b1874b  83c404               add esp, 4
// 00b1874e  c7051c5fe3002c3cb400 mov dword ptr [0xe35f1c], 0xb43c2c
// 00b18758  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18740(int);
void func_00b18740()
{
    G4_func_00b18740(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
