// roc 2007-08 004624c3  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004624c3
//
// 004624c3  b8c9244600           mov eax, 0x4624c9
// 004624c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004624c3()
{
    return &G;
}
