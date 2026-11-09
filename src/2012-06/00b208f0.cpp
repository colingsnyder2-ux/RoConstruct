// roc 2012-06 00b208f0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b208f0
//
// 00b208f0  a1145ae500           mov eax, dword ptr [0xe55a14]
// 00b208f5  50                   push eax
// 00b208f6  e81918e6ff           call 0x982114
// 00b208fb  83c404               add esp, 4
// 00b208fe  c705ec59e5002c3cb400 mov dword ptr [0xe559ec], 0xb43c2c
// 00b20908  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b208f0(int);
void func_00b208f0()
{
    G4_func_00b208f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
