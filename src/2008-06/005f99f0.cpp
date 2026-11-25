// from server: 100% by Xemicl
﻿#include <exception>
// from server: 100% by colin
// roc 2008-06 005f41f0  unit: VWinHttpRequest_source::?$stream_buffer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f41f0
//
// 005f41f0  55                   push ebp
// 005f41f1  8bec                 mov ebp, esp
// 005f41f3  6aff                 push -1
// 005f41f5  6800757d00           push 0x7d7500
// 005f41fa  64a100000000         mov eax, dword ptr fs:[0]
// 005f4200  50                   push eax
// 005f4201  64892500000000       mov dword ptr fs:[0], esp
// 005f4208  51                   push ecx
// 005f4209  8b4124               mov eax, dword ptr [ecx + 0x24]
// 005f420c  8b5114               mov edx, dword ptr [ecx + 0x14]
// 005f420f  8b00                 mov eax, dword ptr [eax]
// 005f4211  8b12                 mov edx, dword ptr [edx]
// 005f4213  53                   push ebx
// 005f4214  56                   push esi
// 005f4215  2bc2                 sub eax, edx
// 005f4217  57                   push edi
// 005f4218  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f421b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f4222  85c0                 test eax, eax
// 005f4224  7e0f                 jle 0x5f4235
// 005f4226  8b7148               mov esi, dword ptr [ecx + 0x48]
// 005f4229  50                   push eax
// 005f422a  52                   push edx
// 005f422b  56                   push esi
// 005f422c  83c140               add ecx, 0x40
// 005f422f  51                   push ecx
// 005f4230  e83b190000           call 0x5f5b70
// 005f4235  8b4948               mov ecx, dword ptr [ecx + 0x48]
// 005f4238  b301                 mov bl, 1
// 005f423a  85c9                 test ecx, ecx
// 005f423c  740d                 je 0x5f424b
// 005f423e  ff1570238000         call dword ptr [0x802370]
// 005f4244  83f8ff               cmp eax, -1
// 005f4247  7502                 jne 0x5f424b
// 005f4249  32db                 xor bl, bl
// 005f424b  8ac3                 mov al, bl
// 005f424d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f4250  64890d00000000       mov dword ptr fs:[0], ecx
// 005f4257  5f                   pop edi
// 005f4258  5e                   pop esi
// 005f4259  5b                   pop ebx
// 005f425a  8be5                 mov esp, ebp
// 005f425c  5d                   pop ebp
// 005f425d  c3                   ret 
// 005f425e  b864425f00           mov eax, 0x5f4264
// 005f4263  c3                   ret 
// 005f4264  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f4267  5f                   pop edi
// 005f4268  5e                   pop esi
// 005f4269  32c0                 xor al, al
// 005f426b  64890d00000000       mov dword ptr fs:[0], ecx
// 005f4272  5b                   pop ebx
// 005f4273  8be5                 mov esp, ebp
// 005f4275  5d                   pop ebp
// 005f4276  c3                   ret 

namespace std {
    template<class T> struct char_traits;
    template<class T, class Traits> class basic_streambuf;
}

typedef std::basic_streambuf<char, std::char_traits<char> > Buffer;
typedef int (__thiscall *SyncFunction)(Buffer*);

extern SyncFunction pubsync;
__declspec(noreturn) void __stdcall write_buffer(
    void*, Buffer*, const char*, int);

struct S {
    char padding0[0x14];
    char** begin;
    char padding1[0x0C];
    char** end;
    char padding2[0x18];
    char writer[8];
    Buffer* output;

    bool flush(Buffer* sb)
    {
        bool result = true;
        if (sb && pubsync(sb) == -1)
            result = false;
        return result;
    }
    int sync();
};

int S::sync()
{
    try {
        const char* last = *end;
        const char* first = *begin;
        int count = last - first;
        if (count > 0) {
            Buffer* out = output;
            write_buffer(writer, out, first, count);
        }
        flush(output);
        return 0;
    }
    catch (std::exception&) {
        return -1;
    }
}