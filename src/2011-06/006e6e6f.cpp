// roc 2011-06 006e6e6f  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e6e6f
//
// 006e6e6f  b8756e6e00           mov eax, 0x6e6e75
// 006e6e74  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006e6e6f()
{
    return &G;
}
