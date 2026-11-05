// roc 2012-06 00b1f1a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f1a0
//
// 00b1f1a0  a1fc1fe500           mov eax, dword ptr [0xe51ffc]
// 00b1f1a5  50                   push eax
// 00b1f1a6  e8692fe6ff           call 0x982114
// 00b1f1ab  83c404               add esp, 4
// 00b1f1ae  c705d41fe5002c3cb400 mov dword ptr [0xe51fd4], 0xb43c2c
// 00b1f1b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f1a0(int);
void func_00b1f1a0()
{
    G4_func_00b1f1a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
