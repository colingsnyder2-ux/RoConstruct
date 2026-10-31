// from server: 84% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005f5020  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f5020
//
// 005f5020  55                   push ebp
// 005f5021  8bec                 mov ebp, esp
// 005f5023  6aff                 push -1
// 005f5025  68e0757d00           push 0x7d75e0
// 005f502a  64a100000000         mov eax, dword ptr fs:[0]
// 005f5030  50                   push eax
// 005f5031  64892500000000       mov dword ptr fs:[0], esp
// 005f5038  83ec08               sub esp, 8
// 005f503b  8b4124               mov eax, dword ptr [ecx + 0x24]
// 005f503e  8b00                 mov eax, dword ptr [eax]
// 005f5040  53                   push ebx
// 005f5041  56                   push esi
// 005f5042  8b7114               mov esi, dword ptr [ecx + 0x14]
// 005f5045  2b06                 sub eax, dword ptr [esi]
// 005f5047  57                   push edi
// 005f5048  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f504b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f5052  85c0                 test eax, eax
// 005f5054  7e16                 jle 0x5f506c
// 005f5056  8b5148               mov edx, dword ptr [ecx + 0x48]
// 005f5059  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 005f505c  8916                 mov dword ptr [esi], edx
// 005f505e  8b7124               mov esi, dword ptr [ecx + 0x24]
// 005f5061  03c2                 add eax, edx
// 005f5063  8916                 mov dword ptr [esi], edx
// 005f5065  2bc2                 sub eax, edx
// 005f5067  8b5134               mov edx, dword ptr [ecx + 0x34]
// 005f506a  8902                 mov dword ptr [edx], eax
// 005f506c  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 005f506f  85c9                 test ecx, ecx
// 005f5071  7406                 je 0x5f5079
// 005f5073  ff1570238000         call dword ptr [0x802370]
// 005f5079  33c0                 xor eax, eax
// 005f507b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f507e  64890d00000000       mov dword ptr fs:[0], ecx
// 005f5085  5f                   pop edi
// 005f5086  5e                   pop esi
// 005f5087  5b                   pop ebx
// 005f5088  8be5                 mov esp, ebp
// 005f508a  5d                   pop ebp
// 005f508b  c3                   ret 

namespace std {
    class exception {};
}

struct Stream;
extern int (__thiscall *pubsync)(Stream*);

struct S {
    char pad0[0x14];
    char** first;
    char pad1[0x0c];
    char** current;
    char pad2[0x0c];
    int* available;
    char pad3[0x0c];
    Stream* stream;
    char* buffer;
    int length;

    int sync();
};

int S::sync()
{
    int count = *current - *first;
    try {
        if (count > 0) {
            char* start = buffer;
            char* end = start + length;
            *first = start;
            *current = start;
            *available = end - start;
        }
        if (stream)
            pubsync(stream);
        return 0;
    }
    catch (const std::exception&) {
        volatile int result = -1;
        return result;
    }
}
