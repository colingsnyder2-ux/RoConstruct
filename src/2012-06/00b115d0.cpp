// roc 2012-06 00b115d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b115d0
//
// 00b115d0  a1147de100           mov eax, dword ptr [0xe17d14]
// 00b115d5  50                   push eax
// 00b115d6  e8390be7ff           call 0x982114
// 00b115db  83c404               add esp, 4
// 00b115de  c705ec7ce1002c3cb400 mov dword ptr [0xe17cec], 0xb43c2c
// 00b115e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b115d0(int);
void func_00b115d0()
{
    G4_func_00b115d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
