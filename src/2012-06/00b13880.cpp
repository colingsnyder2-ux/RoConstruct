// roc 2012-06 00b13880  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13880
//
// 00b13880  c705f815e2002c3cb400 mov dword ptr [0xe215f8], 0xb43c2c
// 00b1388a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b13880;
extern char G2_func_00b13880;
void func_00b13880()
{
    G1_func_00b13880 = &G2_func_00b13880;
}
