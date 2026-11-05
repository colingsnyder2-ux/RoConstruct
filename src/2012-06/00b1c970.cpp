// roc 2012-06 00b1c970  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c970
//
// 00b1c970  a18cd3e400           mov eax, dword ptr [0xe4d38c]
// 00b1c975  50                   push eax
// 00b1c976  e89957e6ff           call 0x982114
// 00b1c97b  83c404               add esp, 4
// 00b1c97e  c70564d3e4002c3cb400 mov dword ptr [0xe4d364], 0xb43c2c
// 00b1c988  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c970(int);
void func_00b1c970()
{
    G4_func_00b1c970(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
