// roc 2012-06 00b1c5f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c5f0
//
// 00b1c5f0  a118b2e400           mov eax, dword ptr [0xe4b218]
// 00b1c5f5  50                   push eax
// 00b1c5f6  e8195be6ff           call 0x982114
// 00b1c5fb  83c404               add esp, 4
// 00b1c5fe  c705f0b1e4002c3cb400 mov dword ptr [0xe4b1f0], 0xb43c2c
// 00b1c608  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c5f0(int);
void func_00b1c5f0()
{
    G4_func_00b1c5f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
