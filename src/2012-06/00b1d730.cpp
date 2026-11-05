// roc 2012-06 00b1d730  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d730
//
// 00b1d730  a18cefe400           mov eax, dword ptr [0xe4ef8c]
// 00b1d735  50                   push eax
// 00b1d736  e8d949e6ff           call 0x982114
// 00b1d73b  83c404               add esp, 4
// 00b1d73e  c70564efe4002c3cb400 mov dword ptr [0xe4ef64], 0xb43c2c
// 00b1d748  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d730(int);
void func_00b1d730()
{
    G4_func_00b1d730(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
