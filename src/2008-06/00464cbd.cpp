// roc 2008-06 00464cbd  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00464cbd
//
// 00464cbd  b8c34c4600           mov eax, 0x464cc3
// 00464cc2  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00464cbd()
{
    return &G;
}
