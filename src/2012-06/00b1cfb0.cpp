// roc 2012-06 00b1cfb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cfb0
//
// 00b1cfb0  a1ccdbe400           mov eax, dword ptr [0xe4dbcc]
// 00b1cfb5  50                   push eax
// 00b1cfb6  e85951e6ff           call 0x982114
// 00b1cfbb  83c404               add esp, 4
// 00b1cfbe  c705a4dbe4002c3cb400 mov dword ptr [0xe4dba4], 0xb43c2c
// 00b1cfc8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cfb0(int);
void func_00b1cfb0()
{
    G4_func_00b1cfb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
