// roc 2012-06 00b17490  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17490
//
// 00b17490  a18018e300           mov eax, dword ptr [0xe31880]
// 00b17495  50                   push eax
// 00b17496  e879ace6ff           call 0x982114
// 00b1749b  83c404               add esp, 4
// 00b1749e  c7055818e3002c3cb400 mov dword ptr [0xe31858], 0xb43c2c
// 00b174a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17490(int);
void func_00b17490()
{
    G4_func_00b17490(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
