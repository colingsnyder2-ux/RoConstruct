// roc 2012-06 00b1c750  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c750
//
// 00b1c750  a138b4e400           mov eax, dword ptr [0xe4b438]
// 00b1c755  50                   push eax
// 00b1c756  e8b959e6ff           call 0x982114
// 00b1c75b  83c404               add esp, 4
// 00b1c75e  c70510b4e4002c3cb400 mov dword ptr [0xe4b410], 0xb43c2c
// 00b1c768  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c750(int);
void func_00b1c750()
{
    G4_func_00b1c750(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
