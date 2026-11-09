// roc 2012-06 00b1e110  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e110
//
// 00b1e110  a1ec01e500           mov eax, dword ptr [0xe501ec]
// 00b1e115  50                   push eax
// 00b1e116  e8f93fe6ff           call 0x982114
// 00b1e11b  83c404               add esp, 4
// 00b1e11e  c705c001e5002c3cb400 mov dword ptr [0xe501c0], 0xb43c2c
// 00b1e128  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e110(int);
void func_00b1e110()
{
    G4_func_00b1e110(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
