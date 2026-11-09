// from server: 81% by EspClaude
// from server: 100% by colin
// roc 2008-06 005f8060  unit: std::D::V?$allocator::V?$basic_gzip_compressor::?$stream_buffer  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f8060
//
// 005f8060  55                   push ebp
// 005f8061  8bec                 mov ebp, esp
// 005f8063  6aff                 push -1
// 005f8065  6840797d00           push 0x7d7940
// 005f806a  64a100000000         mov eax, dword ptr fs:[0]
// 005f8070  50                   push eax
// 005f8071  64892500000000       mov dword ptr fs:[0], esp
// 005f8078  51                   push ecx
// 005f8079  53                   push ebx
// 005f807a  56                   push esi
// 005f807b  57                   push edi
// 005f807c  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f807f  8bf1                 mov esi, ecx
// 005f8081  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f8088  e8f3fcffff           call 0x5f7d80
// 005f808d  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 005f8093  85c9                 test ecx, ecx
// 005f8095  7406                 je 0x5f809d
// 005f8097  ff1570238000         call dword ptr [0x802370]

// from server: 87% by king_originala
struct StreamBuffer;

typedef int (__thiscall *SyncFunction)(StreamBuffer*);
extern SyncFunction syncFunction;

struct S {
    char padding[0x8c];
    StreamBuffer* buffer;

    void finish();
    bool f();
};

bool S::f()
{
    try {
        finish();
        if (buffer)
            syncFunction(buffer);
    }
    catch (...) {
        throw;
    }
    return false;
}
