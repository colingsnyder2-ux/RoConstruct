// roc 2012-06 00b18bf0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18bf0
//
// 00b18bf0  a18c73e300           mov eax, dword ptr [0xe3738c]
// 00b18bf5  50                   push eax
// 00b18bf6  e81995e6ff           call 0x982114
// 00b18bfb  83c404               add esp, 4
// 00b18bfe  c7056473e3002c3cb400 mov dword ptr [0xe37364], 0xb43c2c
// 00b18c08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18bf0(int);
void func_00b18bf0()
{
    G4_func_00b18bf0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
