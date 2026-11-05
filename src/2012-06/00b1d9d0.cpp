// roc 2012-06 00b1d9d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d9d0
//
// 00b1d9d0  a1e4efe400           mov eax, dword ptr [0xe4efe4]
// 00b1d9d5  50                   push eax
// 00b1d9d6  e83947e6ff           call 0x982114
// 00b1d9db  83c404               add esp, 4
// 00b1d9de  c705bcefe4002c3cb400 mov dword ptr [0xe4efbc], 0xb43c2c
// 00b1d9e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d9d0(int);
void func_00b1d9d0()
{
    G4_func_00b1d9d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
