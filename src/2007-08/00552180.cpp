// from server: 82% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 50% by colin
// roc 2007-08 00552180  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00552180
//
// 00552180  55                   push ebp
// 00552181  8bec                 mov ebp, esp
// 00552183  6aff                 push -1
// 00552185  68d02b7500           push 0x752bd0
// 0055218a  64a100000000         mov eax, dword ptr fs:[0]
// 00552190  50                   push eax
// 00552191  64892500000000       mov dword ptr fs:[0], esp
// 00552198  51                   push ecx
// 00552199  53                   push ebx
// 0055219a  56                   push esi
// 0055219b  57                   push edi
// 0055219c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0055219f  8bf1                 mov esi, ecx
// 005521a1  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005521a8  e8e3feffff           call 0x552090
// 005521ad  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 005521b3  85c9                 test ecx, ecx
// 005521b5  7406                 je 0x5521bd
// 005521b7  ff1504e67700         call dword ptr [0x77e604]
// boost 1.34 iostreams indirect_streambuf::strict_sync shape:
// try { sync_impl(); return obj().flush(next_); } catch (...) { return false; }
// next_ at +0x8c (mov ecx,[esi+0x8c]); pubsync called through the msvcp80 IAT.
struct streambuf_imp {
    __declspec(dllimport) int pubsync();
};

struct indirect_streambuf {
    char pad0[0x8c];
    streambuf_imp* next_;

    void sync_impl();
    bool strict_sync();
};

bool indirect_streambuf::strict_sync()
{
    try {
        sync_impl();
        bool result = false;
        if (next_ && next_->pubsync() == -1)
            result = false;
        return result;
    } catch (...) {
        return false;
    }
}
