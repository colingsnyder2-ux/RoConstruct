// roc 2007-08 00461078  unit: RBX::VRunService::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461078
//
// 00461078  b87e104600           mov eax, 0x46107e
// 0046107d  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00461078()
{
    return &G;
}
