// roc 2012-06 00b1f060  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f060
//
// 00b1f060  a12c24e500           mov eax, dword ptr [0xe5242c]
// 00b1f065  50                   push eax
// 00b1f066  e8a930e6ff           call 0x982114
// 00b1f06b  83c404               add esp, 4
// 00b1f06e  c7050424e5002c3cb400 mov dword ptr [0xe52404], 0xb43c2c
// 00b1f078  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f060(int);
void func_00b1f060()
{
    G4_func_00b1f060(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
