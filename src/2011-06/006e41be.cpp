// roc 2011-06 006e41be  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e41be
//
// 006e41be  b8c4416e00           mov eax, 0x6e41c4
// 006e41c3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006e41be()
{
    return &G;
}
