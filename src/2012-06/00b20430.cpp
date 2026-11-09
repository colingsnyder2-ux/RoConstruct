// roc 2012-06 00b20430  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20430
//
// 00b20430  a1f452e500           mov eax, dword ptr [0xe552f4]
// 00b20435  50                   push eax
// 00b20436  e8d91ce6ff           call 0x982114
// 00b2043b  83c404               add esp, 4
// 00b2043e  c705cc52e5002c3cb400 mov dword ptr [0xe552cc], 0xb43c2c
// 00b20448  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20430(int);
void func_00b20430()
{
    G4_func_00b20430(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
