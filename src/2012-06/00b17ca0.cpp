// roc 2012-06 00b17ca0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17ca0
//
// 00b17ca0  a19c38e300           mov eax, dword ptr [0xe3389c]
// 00b17ca5  50                   push eax
// 00b17ca6  e869a4e6ff           call 0x982114
// 00b17cab  83c404               add esp, 4
// 00b17cae  c7057438e3002c3cb400 mov dword ptr [0xe33874], 0xb43c2c
// 00b17cb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17ca0(int);
void func_00b17ca0()
{
    G4_func_00b17ca0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
