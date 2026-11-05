// roc 2012-06 00b1c430  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c430
//
// 00b1c430  a170aee400           mov eax, dword ptr [0xe4ae70]
// 00b1c435  50                   push eax
// 00b1c436  e8d95ce6ff           call 0x982114
// 00b1c43b  83c404               add esp, 4
// 00b1c43e  c70548aee4002c3cb400 mov dword ptr [0xe4ae48], 0xb43c2c
// 00b1c448  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c430(int);
void func_00b1c430()
{
    G4_func_00b1c430(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
