// roc 2012-06 00b15080  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15080
//
// 00b15080  a128a0e200           mov eax, dword ptr [0xe2a028]
// 00b15085  50                   push eax
// 00b15086  e889d0e6ff           call 0x982114
// 00b1508b  83c404               add esp, 4
// 00b1508e  c70500a0e2002c3cb400 mov dword ptr [0xe2a000], 0xb43c2c
// 00b15098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15080(int);
void func_00b15080()
{
    G4_func_00b15080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
