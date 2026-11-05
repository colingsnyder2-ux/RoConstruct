// roc 2012-06 00b18510  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18510
//
// 00b18510  a1d85ce300           mov eax, dword ptr [0xe35cd8]
// 00b18515  50                   push eax
// 00b18516  e8f99be6ff           call 0x982114
// 00b1851b  83c404               add esp, 4
// 00b1851e  c705b05ce3002c3cb400 mov dword ptr [0xe35cb0], 0xb43c2c
// 00b18528  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18510(int);
void func_00b18510()
{
    G4_func_00b18510(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
