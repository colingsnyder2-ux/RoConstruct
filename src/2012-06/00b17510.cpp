// roc 2012-06 00b17510  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17510
//
// 00b17510  a1e818e300           mov eax, dword ptr [0xe318e8]
// 00b17515  50                   push eax
// 00b17516  e8f9abe6ff           call 0x982114
// 00b1751b  83c404               add esp, 4
// 00b1751e  c705c018e3002c3cb400 mov dword ptr [0xe318c0], 0xb43c2c
// 00b17528  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17510(int);
void func_00b17510()
{
    G4_func_00b17510(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
