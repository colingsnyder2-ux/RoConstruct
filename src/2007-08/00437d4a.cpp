// roc 2007-08 00437d4a  unit: RBX::VStandardOut::?$MarshaledListener::EventData  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437d4a
//
// 00437d4a  b8507d4300           mov eax, 0x437d50
// 00437d4f  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00437d4a()
{
    return &G;
}
