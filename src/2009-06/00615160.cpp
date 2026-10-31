// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005f4120  unit: UString_sink::?$stream_buffer  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f4120
//
// 005f4120  55                   push ebp
// 005f4121  8bec                 mov ebp, esp
// 005f4123  6aff                 push -1
// 005f4125  68f0747d00           push 0x7d74f0
// 005f412a  64a100000000         mov eax, dword ptr fs:[0]
// 005f4130  50                   push eax
// 005f4131  64892500000000       mov dword ptr fs:[0], esp
// 005f4138  83ec08               sub esp, 8
// 005f413b  53                   push ebx
// 005f413c  56                   push esi
// 005f413d  8bf1                 mov esi, ecx
// 005f413f  8b4624               mov eax, dword ptr [esi + 0x24]
// 005f4142  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005f4145  8b00                 mov eax, dword ptr [eax]
// 005f4147  8b09                 mov ecx, dword ptr [ecx]
// 005f4149  2bc1                 sub eax, ecx
// 005f414b  57                   push edi
// 005f414c  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f414f  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f4156  85c0                 test eax, eax
// 005f4158  7e24                 jle 0x5f417e
// 005f415a  50                   push eax
// 005f415b  51                   push ecx
// 005f415c  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005f415f  ff1540258000         call dword ptr [0x802540]
// 005f4165  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 005f4168  8b5614               mov edx, dword ptr [esi + 0x14]
// 005f416b  8b4650               mov eax, dword ptr [esi + 0x50]
// 005f416e  890a                 mov dword ptr [edx], ecx
// 005f4170  8b5624               mov edx, dword ptr [esi + 0x24]
// 005f4173  03c1                 add eax, ecx
// 005f4175  890a                 mov dword ptr [edx], ecx
// 005f4177  2bc1                 sub eax, ecx
// 005f4179  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005f417c  8901                 mov dword ptr [ecx], eax
// 005f417e  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 005f4181  85c9                 test ecx, ecx
// 005f4183  7406                 je 0x5f418b
// 005f4185  ff1570238000         call dword ptr [0x802370]
// 005f418b  33c0                 xor eax, eax
// 005f418d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f4190  64890d00000000       mov dword ptr fs:[0], ecx
// 005f4197  5f                   pop edi
// 005f4198  5e                   pop esi
// 005f4199  5b                   pop ebx
// 005f419a  8be5                 mov esp, ebp
// 005f419c  5d                   pop ebp
// 005f419d  c3                   ret 

typedef void* (__thiscall *AppendFunction)(void*, const char*, unsigned int);
typedef int (__thiscall *SyncFunction)(void*);

extern AppendFunction basic_string_append;
extern SyncFunction basic_streambuf_pubsync;

struct S {
    char reserved0[0x14];
    char** first;
    char reserved1[0x0C];
    char** next;
    char reserved2[0x0C];
    int* remaining;
    char reserved3[0x08];
    void* string;
    char reserved4[0x04];
    void* streambuf;
    char* buffer;
    int capacity;

    int sync();
};

int S::sync()
{
    char* finish = *next;
    char* start = *first;
    int count = finish - start;
    try {
        if (count > 0) {
            basic_string_append(string, start, count);
            char* begin = buffer;
            char* end = begin + capacity;
            *first = begin;
            *next = begin;
            *remaining = end - begin;
        }
        if (streambuf)
            basic_streambuf_pubsync(streambuf);
    }
    catch (...) {
        volatile int result = -1;
        return result;
    }
    return 0;
}
