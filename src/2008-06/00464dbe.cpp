// roc 2008-06 00464dbe  unit: RBX::VRunService::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00464dbe
//
// 00464dbe  b8c44d4600           mov eax, 0x464dc4
// 00464dc3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00464dbe()
{
    return &G;
}
