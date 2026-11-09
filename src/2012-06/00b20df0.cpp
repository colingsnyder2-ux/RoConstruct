// roc 2012-06 00b20df0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20df0
//
// 00b20df0  a1f863e500           mov eax, dword ptr [0xe563f8]
// 00b20df5  50                   push eax
// 00b20df6  e81913e6ff           call 0x982114
// 00b20dfb  83c404               add esp, 4
// 00b20dfe  c705d063e5002c3cb400 mov dword ptr [0xe563d0], 0xb43c2c
// 00b20e08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20df0(int);
void func_00b20df0()
{
    G4_func_00b20df0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
