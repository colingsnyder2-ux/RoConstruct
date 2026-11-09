// roc 2012-06 00b11ec0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ec0
//
// 00b11ec0  a1e099e100           mov eax, dword ptr [0xe199e0]
// 00b11ec5  50                   push eax
// 00b11ec6  e84902e7ff           call 0x982114
// 00b11ecb  83c404               add esp, 4
// 00b11ece  c705b499e1002c3cb400 mov dword ptr [0xe199b4], 0xb43c2c
// 00b11ed8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11ec0(int);
void func_00b11ec0()
{
    G4_func_00b11ec0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
