// roc 2007-08 004546f5  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004546f5
//
// 004546f5  b8fb464500           mov eax, 0x4546fb
// 004546fa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004546f5()
{
    return &G;
}
