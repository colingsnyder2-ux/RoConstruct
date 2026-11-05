// roc 2012-06 00b12100  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12100
//
// 00b12100  a16497e100           mov eax, dword ptr [0xe19764]
// 00b12105  50                   push eax
// 00b12106  e80900e7ff           call 0x982114
// 00b1210b  83c404               add esp, 4
// 00b1210e  c7053897e1002c3cb400 mov dword ptr [0xe19738], 0xb43c2c
// 00b12118  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12100(int);
void func_00b12100()
{
    G4_func_00b12100(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
