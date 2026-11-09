// roc 2012-06 00b18530  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18530
//
// 00b18530  a19062e300           mov eax, dword ptr [0xe36290]
// 00b18535  50                   push eax
// 00b18536  e8d99be6ff           call 0x982114
// 00b1853b  83c404               add esp, 4
// 00b1853e  c7056862e3002c3cb400 mov dword ptr [0xe36268], 0xb43c2c
// 00b18548  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18530(int);
void func_00b18530()
{
    G4_func_00b18530(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
