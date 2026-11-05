// roc 2012-06 00b1e920  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e920
//
// 00b1e920  a14010e500           mov eax, dword ptr [0xe51040]
// 00b1e925  50                   push eax
// 00b1e926  e8e937e6ff           call 0x982114
// 00b1e92b  83c404               add esp, 4
// 00b1e92e  c7051410e5002c3cb400 mov dword ptr [0xe51014], 0xb43c2c
// 00b1e938  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e920(int);
void func_00b1e920()
{
    G4_func_00b1e920(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
