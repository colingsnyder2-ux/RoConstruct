// roc 2012-06 00b12220  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12220
//
// 00b12220  a1049be100           mov eax, dword ptr [0xe19b04]
// 00b12225  50                   push eax
// 00b12226  e8e9fee6ff           call 0x982114
// 00b1222b  83c404               add esp, 4
// 00b1222e  c705dc9ae1002c3cb400 mov dword ptr [0xe19adc], 0xb43c2c
// 00b12238  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12220(int);
void func_00b12220()
{
    G4_func_00b12220(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
