// from server: 90% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005f4ef0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f4ef0
//
// 005f4ef0  55                   push ebp
// 005f4ef1  8bec                 mov ebp, esp
// 005f4ef3  6aff                 push -1
// 005f4ef5  68d0757d00           push 0x7d75d0
// 005f4efa  64a100000000         mov eax, dword ptr fs:[0]
// 005f4f00  50                   push eax
// 005f4f01  64892500000000       mov dword ptr fs:[0], esp
// 005f4f08  51                   push ecx
// 005f4f09  8b4124               mov eax, dword ptr [ecx + 0x24]
// 005f4f0c  8b00                 mov eax, dword ptr [eax]
// 005f4f0e  53                   push ebx
// 005f4f0f  56                   push esi
// 005f4f10  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005f4f13  2b06                 sub eax, dword ptr [esi]
// 005f4f15  57                   push edi
// 005f4f16  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f4f19  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f4f20  85c0                 test eax, eax
// 005f4f22  7e16                 jle 0x5f4f3a
// 005f4f24  8b5148               mov edx, dword ptr [ecx + 0x48]
// 005f4f27  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 005f4f2a  8916                 mov dword ptr [esi], edx
// 005f4f2c  8b7124               mov esi, dword ptr [ecx + 0x24]
// 005f4f2f  03c2                 add eax, edx
// 005f4f31  8916                 mov dword ptr [esi], edx
// 005f4f33  2bc2                 sub eax, edx
// 005f4f35  8b5134               mov edx, dword ptr [ecx + 0x34]
// 005f4f38  8902                 mov dword ptr [edx], eax
// 005f4f3a  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 005f4f3d  b301                 mov bl, 1
// 005f4f3f  85c9                 test ecx, ecx
// 005f4f41  740d                 je 0x5f4f50
// 005f4f43  ff1570238000         call dword ptr [0x802370]
// 005f4f49  83f8ff               cmp eax, -1
// 005f4f4c  7502                 jne 0x5f4f50
// 005f4f4e  32db                 xor bl, bl
// 005f4f50  8ac3                 mov al, bl
// 005f4f52  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f4f55  64890d00000000       mov dword ptr fs:[0], ecx
// 005f4f5c  5f                   pop edi
// 005f4f5d  5e                   pop esi
// 005f4f5e  5b                   pop ebx
// 005f4f5f  8be5                 mov esp, ebp
// 005f4f61  5d                   pop ebp
// 005f4f62  c3                   ret 

typedef int (__thiscall *SyncFunction)(void *);
extern SyncFunction pubsync;

struct S {
    char padding0[0x14];
    char **base;
    char padding1[0x0c];
    char **current;
    char padding2[0x0c];
    int *remaining;
    char padding3[0x0c];
    void *stream;
    char *buffer;
    int size;

    bool sync();
};

bool S::sync()
{
    int count = *current - *base;
    try {
        if (count > 0) {
            char *first = buffer;
            char *last = first + size;
            *base = first;
            *current = first;
            *remaining = last - first;
        }
        bool result = true;
        if (stream && pubsync(stream) == -1)
            result = false;
        return result;
    }
    catch (...) {
        return false;
    }
}
