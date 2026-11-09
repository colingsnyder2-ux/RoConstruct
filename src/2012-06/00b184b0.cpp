// roc 2012-06 00b184b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b184b0
//
// 00b184b0  a1f85fe300           mov eax, dword ptr [0xe35ff8]
// 00b184b5  50                   push eax
// 00b184b6  e8599ce6ff           call 0x982114
// 00b184bb  83c404               add esp, 4
// 00b184be  c705d05fe3002c3cb400 mov dword ptr [0xe35fd0], 0xb43c2c
// 00b184c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b184b0(int);
void func_00b184b0()
{
    G4_func_00b184b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
