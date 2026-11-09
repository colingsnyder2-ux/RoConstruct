// roc 2012-06 00b17bc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17bc0
//
// 00b17bc0  a15833e300           mov eax, dword ptr [0xe33358]
// 00b17bc5  50                   push eax
// 00b17bc6  e849a5e6ff           call 0x982114
// 00b17bcb  83c404               add esp, 4
// 00b17bce  c7053033e3002c3cb400 mov dword ptr [0xe33330], 0xb43c2c
// 00b17bd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17bc0(int);
void func_00b17bc0()
{
    G4_func_00b17bc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
