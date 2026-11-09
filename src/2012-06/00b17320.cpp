// roc 2012-06 00b17320  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17320
//
// 00b17320  a18817e300           mov eax, dword ptr [0xe31788]
// 00b17325  50                   push eax
// 00b17326  e8e9ade6ff           call 0x982114
// 00b1732b  83c404               add esp, 4
// 00b1732e  c7055c17e3002c3cb400 mov dword ptr [0xe3175c], 0xb43c2c
// 00b17338  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17320(int);
void func_00b17320()
{
    G4_func_00b17320(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
