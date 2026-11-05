// roc 2008-06 005f5f1d  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f5f1d
//
// 005f5f1d  b80a5f5f00           mov eax, 0x5f5f0a
// 005f5f22  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_005f5f1d()
{
    return &G;
}
