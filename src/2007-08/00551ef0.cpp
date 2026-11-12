// from server: 82% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 50% by Intel
// roc 2007-08 00551ef0  unit: std::D::V?$allocator::U?$basic_zlib_decompressor::?$stream_buffer  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00551ef0
//
// 00551ef0  55                   push ebp
// 00551ef1  8bec                 mov ebp, esp
// 00551ef3  6aff                 push -1
// 00551ef5  68b02b7500           push 0x752bb0
// 00551efa  64a100000000         mov eax, dword ptr fs:[0]
// 00551f00  50                   push eax
// 00551f01  64892500000000       mov dword ptr fs:[0], esp
// 00551f08  51                   push ecx
// 00551f09  53                   push ebx
// 00551f0a  56                   push esi
// 00551f0b  57                   push edi
// 00551f0c  8965f0               mov dword ptr [ebp - 0x10], esp
// 00551f0f  8bf1                 mov esi, ecx
// 00551f11  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00551f18  e803fbffff           call 0x551a20
// 00551f1d  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00551f20  85c9                 test ecx, ecx
// 00551f22  7406                 je 0x551f2a
// 00551f24  ff1504e67700         call dword ptr [0x77e604]
// 00551f2a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00551f2d  5f                   pop edi
// 00551f2e  5e                   pop esi
// 00551f2f  32c0                 xor al, al
// 00551f31  64890d00000000       mov dword ptr fs:[0], ecx
// 00551f38  5b                   pop ebx
// 00551f39  8be5                 mov esp, ebp
// 00551f3b  5d                   pop ebp
// 00551f3c  c3                   ret 
// 00551f3d  b82a1f5500           mov eax, 0x551f2a
// 00551f42  c3                   ret 

// boost 1.34 iostreams indirect_streambuf::strict_sync shape:
// try { sync_impl(); return obj().flush(next_); } catch (...) { return false; }
// next_ at +0x4c (mov ecx,[esi+0x4c]); pubsync called through the msvcp80 IAT.
struct streambuf_imp {
    __declspec(dllimport) int pubsync();
};

struct indirect_streambuf {
    char pad0[0x4c];
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
