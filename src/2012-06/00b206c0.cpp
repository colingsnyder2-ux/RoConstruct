// roc 2012-06 00b206c0  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b206c0
//
// 00b206c0  c705c855e5002c3cb400 mov dword ptr [0xe555c8], 0xb43c2c
// 00b206ca  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b206c0;
extern char G2_func_00b206c0;
void func_00b206c0()
{
    G1_func_00b206c0 = &G2_func_00b206c0;
}
