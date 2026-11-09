// roc 2011-06 005f3227  unit: $$A6A_NXZ$0A::?$CallbackDescImpl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005f3227
//
// 005f3227  b82d325f00           mov eax, 0x5f322d
// 005f322c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f3227()
{
    return &G;
}
