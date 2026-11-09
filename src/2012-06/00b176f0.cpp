// roc 2012-06 00b176f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b176f0
//
// 00b176f0  a17020e300           mov eax, dword ptr [0xe32070]
// 00b176f5  50                   push eax
// 00b176f6  e819aae6ff           call 0x982114
// 00b176fb  83c404               add esp, 4
// 00b176fe  c7054820e3002c3cb400 mov dword ptr [0xe32048], 0xb43c2c
// 00b17708  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b176f0(int);
void func_00b176f0()
{
    G4_func_00b176f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
