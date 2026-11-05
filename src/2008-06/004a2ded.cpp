// from server: 51% by colin
// from server: 50% by colin
// roc 2008-06 004a2ded  unit: RBX::Network::Server::ClientProxy  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a2ded
//
// 004a2ded  33c0                 xor eax, eax
// 004a2def  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a2df2  5f                   pop edi
// 004a2df3  5e                   pop esi
// 004a2df4  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2dfb  5b                   pop ebx
// 004a2dfc  83c560               add ebp, 0x60
// 004a2dff  8be5                 mov esp, ebp
// 004a2e01  5d                   pop ebp
// 004a2e02  c20800               ret 8
// 004a2e05  6a04                 push 4
// 004a2e07  8d8d68ffffff         lea ecx, [ebp - 0x98]
// 004a2e0d  51                   push ecx
// 004a2e0e  8d4d54               lea ecx, [ebp + 0x54]
// 004a2e11  e82a561000           call 0x5a8440
// 004a2e16  83781810             cmp dword ptr [eax + 0x18], 0x10
// 004a2e1a  c645fc06             mov byte ptr [ebp - 4], 6
// 004a2e1e  7205                 jb 0x4a2e25
// 004a2e20  8b7004               mov esi, dword ptr [eax + 4]
// 004a2e23  eb03                 jmp 0x4a2e28
// 004a2e25  8d7004               lea esi, [eax + 4]
// 004a2e28  6a01                 push 1
// 004a2e2a  8bcf                 mov ecx, edi
// 004a2e2c  e87f6a0000           call 0x4a98b0
// 004a2e31  50                   push eax
// 004a2e32  56                   push esi
// 004a2e33  8d5584               lea edx, [ebp - 0x7c]
// 004a2e36  6858358200           push 0x823558
// 004a2e3b  52                   push edx
// 004a2e3c  e8cf6c0600           call 0x509b10
// 004a2e41  83c410               add esp, 0x10
// 004a2e44  50                   push eax
// 004a2e45  8d4dc8               lea ecx, [ebp - 0x38]
// 004a2e48  c645fc07             mov byte ptr [ebp - 4], 7
// 004a2e4c  e8ff6ef6ff           call 0x409d50
// 004a2e51  68c81b8d00           push 0x8d1bc8
// 004a2e56  8d45c8               lea eax, [ebp - 0x38]
// 004a2e59  50                   push eax
// 004a2e5a  e82de71f00           call 0x6a158c
#include <intrin.h>

struct String {
    unsigned long allocator;
    union {
        char local[16];
        char *pointer;
    } storage;
    unsigned long length;
    unsigned long capacity;

    ~String();
    String *substr(String *result, unsigned long position) const;
};

struct Address {
    const char *text(int mode);
};

struct Error {
    unsigned char data[12];

    Error(const String &message);
    ~Error();
};

extern String *__cdecl format(String *result, const char *pattern, ...);
extern const char errorPattern[];
extern unsigned char errorType;
extern "C" __declspec(noreturn) void __stdcall raiseException(void *, void *);

struct S {
    int f(String player, Address *remote);
};

int S::f(String player, Address *remote)
{
    String name;
    _ReadWriteBarrier();
    String *result = player.substr(&name, 4);
    const char *text;
    if (result->capacity >= 16)
        text = result->storage.pointer;
    else
        text = result->storage.local;

    String message;
    Error error(*format(&message, errorPattern, text, remote->text(1)));
    raiseException(&error, &errorType);
}
