// from server: 85% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 57% by Intel
// roc 2007-08 00552000  unit: std::D::V?$allocator::U?$basic_zlib_decompressor::?$stream_buffer  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00552000
//
// 00552000  55                   push ebp
// 00552001  8bec                 mov ebp, esp
// 00552003  6aff                 push -1
// 00552005  68c02b7500           push 0x752bc0
// 0055200a  64a100000000         mov eax, dword ptr fs:[0]
// 00552010  50                   push eax
// 00552011  64892500000000       mov dword ptr fs:[0], esp
// 00552018  51                   push ecx
// 00552019  53                   push ebx
// 0055201a  56                   push esi
// 0055201b  57                   push edi
// 0055201c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0055201f  8bf1                 mov esi, ecx
// 00552021  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00552028  e8f3f9ffff           call 0x551a20
// 0055202d  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00552030  85c9                 test ecx, ecx
// 00552032  7406                 je 0x55203a
// 00552034  ff1504e67700         call dword ptr [0x77e604]
// 0055203a  33c0                 xor eax, eax
// 0055203c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0055203f  64890d00000000       mov dword ptr fs:[0], ecx
// 00552046  5f                   pop edi
// 00552047  5e                   pop esi
// 00552048  5b                   pop ebx
// 00552049  8be5                 mov esp, ebp
// 0055204b  5d                   pop ebp
// 0055204c  c3                   ret 
// 0055204d  b853205500           mov eax, 0x552053
// 00552052  c3                   ret 
// 00552053  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00552056  5f                   pop edi
// 00552057  5e                   pop esi
// 00552058  83c8ff               or eax, 0xffffffff
// 0055205b  64890d00000000       mov dword ptr fs:[0], ecx
// 00552062  5b                   pop ebx

struct Streambuf {
    __declspec(dllimport) int pubsync();
};

struct S {
    char padding0[0x4c];
    Streambuf* next_;

    void sync_impl();
    int sync();
};

int S::sync()
{
    try {
        sync_impl();
        if (next_)
            next_->pubsync();
        return 0;
    } catch (...) {
        return -1;
    }
}
