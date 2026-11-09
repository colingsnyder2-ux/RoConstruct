// roc 2012-06 00b1c290  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c290
//
// 00b1c290  a12cade400           mov eax, dword ptr [0xe4ad2c]
// 00b1c295  50                   push eax
// 00b1c296  e8795ee6ff           call 0x982114
// 00b1c29b  83c404               add esp, 4
// 00b1c29e  c70504ade4002c3cb400 mov dword ptr [0xe4ad04], 0xb43c2c
// 00b1c2a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c290(int);
void func_00b1c290()
{
    G4_func_00b1c290(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
