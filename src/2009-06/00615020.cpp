// from server: 91% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005f3fe0  unit: UString_sink::?$stream_buffer  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f3fe0
//
// 005f3fe0  55                   push ebp
// 005f3fe1  8bec                 mov ebp, esp
// 005f3fe3  6aff                 push -1
// 005f3fe5  68e0747d00           push 0x7d74e0
// 005f3fea  64a100000000         mov eax, dword ptr fs:[0]
// 005f3ff0  50                   push eax
// 005f3ff1  64892500000000       mov dword ptr fs:[0], esp
// 005f3ff8  51                   push ecx
// 005f3ff9  53                   push ebx
// 005f3ffa  56                   push esi
// 005f3ffb  8bf1                 mov esi, ecx
// 005f3ffd  8b4624               mov eax, dword ptr [esi + 0x24]
// 005f4000  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005f4003  8b00                 mov eax, dword ptr [eax]
// 005f4005  8b09                 mov ecx, dword ptr [ecx]
// 005f4007  2bc1                 sub eax, ecx
// 005f4009  57                   push edi
// 005f400a  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f400d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f4014  85c0                 test eax, eax
// 005f4016  7e24                 jle 0x5f403c
// 005f4018  50                   push eax
// 005f4019  51                   push ecx
// 005f401a  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 005f401d  ff1540258000         call dword ptr [0x802540]
// 005f4023  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 005f4026  8b5614               mov edx, dword ptr [esi + 0x14]
// 005f4029  8b4650               mov eax, dword ptr [esi + 0x50]
// 005f402c  890a                 mov dword ptr [edx], ecx
// 005f402e  8b5624               mov edx, dword ptr [esi + 0x24]
// 005f4031  03c1                 add eax, ecx
// 005f4033  890a                 mov dword ptr [edx], ecx
// 005f4035  2bc1                 sub eax, ecx
// 005f4037  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005f403a  8901                 mov dword ptr [ecx], eax
// 005f403c  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 005f403f  b301                 mov bl, 1
// 005f4041  85c9                 test ecx, ecx
// 005f4043  740d                 je 0x5f4052
// 005f4045  ff1570238000         call dword ptr [0x802370]
// 005f404b  83f8ff               cmp eax, -1
// 005f404e  7502                 jne 0x5f4052
// 005f4050  32db                 xor bl, bl
// 005f4052  8ac3                 mov al, bl
// 005f4054  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f4057  64890d00000000       mov dword ptr fs:[0], ecx
// 005f405e  5f                   pop edi
// 005f405f  5e                   pop esi
// 005f4060  5b                   pop ebx
// 005f4061  8be5                 mov esp, ebp
// 005f4063  5d                   pop ebp
// 005f4064  c3                   ret 

struct String {};
struct StreamBuffer {};

typedef String& (__thiscall *AppendFunction)(String*, const char*, unsigned int);
typedef int (__thiscall *SyncFunction)(StreamBuffer*);

extern AppendFunction append;
extern SyncFunction pubsync;

struct S
{
    char padding0[0x14];
    char** begin;
    char padding1[0x0C];
    char** end;
    char padding2[0x0C];
    int* remaining;
    char padding3[0x08];
    String* destination;
    int padding4;
    StreamBuffer* stream;
    char* buffer;
    int capacity;

    bool f();
};

bool S::f()
{
    try
    {
        char* last = *end;
        char* first = *begin;
        int length = last - first;
        if (length > 0)
        {
            append(destination, first, length);
            char* base = buffer;
            char* limit = base + capacity;
            *begin = base;
            *end = base;
            *remaining = limit - base;
        }

        bool result = true;
        if (stream && pubsync(stream) == -1)
            result = false;
        return result;
    }
    catch (...)
    {
        return false;
    }
}
