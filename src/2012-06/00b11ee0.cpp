// roc 2012-06 00b11ee0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ee0
//
// 00b11ee0  a12c97e100           mov eax, dword ptr [0xe1972c]
// 00b11ee5  50                   push eax
// 00b11ee6  e82902e7ff           call 0x982114
// 00b11eeb  83c404               add esp, 4
// 00b11eee  c7050097e1002c3cb400 mov dword ptr [0xe19700], 0xb43c2c
// 00b11ef8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11ee0(int);
void func_00b11ee0()
{
    G4_func_00b11ee0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
