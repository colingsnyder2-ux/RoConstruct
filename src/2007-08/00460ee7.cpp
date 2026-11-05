// roc 2007-08 00460ee7  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460ee7
//
// 00460ee7  b8ed0e4600           mov eax, 0x460eed
// 00460eec  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00460ee7()
{
    return &G;
}
