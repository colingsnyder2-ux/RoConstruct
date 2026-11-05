// roc 2008-06 005f3f50  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f3f50
//
// 005f3f50  b8563f5f00           mov eax, 0x5f3f56
// 005f3f55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f3f50()
{
    return &G;
}
