// roc 2012-06 00b1ceb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ceb0
//
// 00b1ceb0  a12cdbe400           mov eax, dword ptr [0xe4db2c]
// 00b1ceb5  50                   push eax
// 00b1ceb6  e85952e6ff           call 0x982114
// 00b1cebb  83c404               add esp, 4
// 00b1cebe  c70504dbe4002c3cb400 mov dword ptr [0xe4db04], 0xb43c2c
// 00b1cec8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ceb0(int);
void func_00b1ceb0()
{
    G4_func_00b1ceb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
