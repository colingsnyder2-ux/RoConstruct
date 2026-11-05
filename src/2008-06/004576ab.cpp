// roc 2008-06 004576ab  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004576ab
//
// 004576ab  b8b1764500           mov eax, 0x4576b1
// 004576b0  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004576ab()
{
    return &G;
}
