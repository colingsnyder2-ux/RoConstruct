// roc 2008-06 004215b9  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004215b9
//
// 004215b9  b8bf154200           mov eax, 0x4215bf
// 004215be  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004215b9()
{
    return &G;
}
