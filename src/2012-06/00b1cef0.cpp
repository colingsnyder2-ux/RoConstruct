// roc 2012-06 00b1cef0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cef0
//
// 00b1cef0  a1a8dce400           mov eax, dword ptr [0xe4dca8]
// 00b1cef5  50                   push eax
// 00b1cef6  e81952e6ff           call 0x982114
// 00b1cefb  83c404               add esp, 4
// 00b1cefe  c70580dce4002c3cb400 mov dword ptr [0xe4dc80], 0xb43c2c
// 00b1cf08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cef0(int);
void func_00b1cef0()
{
    G4_func_00b1cef0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
