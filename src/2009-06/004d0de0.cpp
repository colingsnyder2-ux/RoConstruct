// from server: 100% by EspClaude
// roc 2009-06 004d0de0  unit: RBX::Network::VClient::?$FactoryProduct  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d0de0
//
// 004d0de0  6aff                 push -1
// 004d0de2  6843ae8500           push 0x85ae43
// 004d0de7  64a100000000         mov eax, dword ptr fs:[0]
// 004d0ded  50                   push eax
// 004d0dee  64892500000000       mov dword ptr fs:[0], esp
// 004d0df5  83ec2c               sub esp, 0x2c
// 004d0df8  56                   push esi
// 004d0df9  8bf1                 mov esi, ecx
// 004d0dfb  833e00               cmp dword ptr [esi], 0
// 004d0dfe  c744243801000000     mov dword ptr [esp + 0x38], 1
// 004d0e06  7514                 jne 0x4d0e1c
// 004d0e08  8d4c2408             lea ecx, [esp + 8]
// 004d0e0c  e8cf86f3ff           call 0x4094e0
// 004d0e11  50                   push eax
// 004d0e12  c644243c02           mov byte ptr [esp + 0x3c], 2
// 004d0e17  e84494f3ff           call 0x40a260
// 004d0e1c  83ec1c               sub esp, 0x1c
// 004d0e1f  8d44247c             lea eax, [esp + 0x7c]
// 004d0e23  8bcc                 mov ecx, esp
// 004d0e25  89642420             mov dword ptr [esp + 0x20], esp
// 004d0e29  50                   push eax
// 004d0e2a  ff15b8e48900         call dword ptr [0x89e4b8]
// 004d0e30  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 004d0e34  51                   push ecx
// 004d0e35  83ec1c               sub esp, 0x1c
// 004d0e38  8d54247c             lea edx, [esp + 0x7c]
// 004d0e3c  8bcc                 mov ecx, esp
// 004d0e3e  89a42498000000       mov dword ptr [esp + 0x98], esp
// 004d0e45  52                   push edx
// 004d0e46  c644247803           mov byte ptr [esp + 0x78], 3
// 004d0e4b  ff15b8e48900         call dword ptr [0x89e4b8]
// 004d0e51  8b06                 mov eax, dword ptr [esi]
// 004d0e53  83c608               add esi, 8
// 004d0e56  c644247401           mov byte ptr [esp + 0x74], 1
// 004d0e5b  8b4004               mov eax, dword ptr [eax + 4]
// 004d0e5e  56                   push esi
// 004d0e5f  ffd0                 call eax
// 004d0e61  83c440               add esp, 0x40
// 004d0e64  8d4c2440             lea ecx, [esp + 0x40]
// 004d0e68  c644243800           mov byte ptr [esp + 0x38], 0
// 004d0e6d  ff15c4e48900         call dword ptr [0x89e4c4]
// 004d0e73  8d4c2460             lea ecx, [esp + 0x60]
// 004d0e77  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004d0e7f  ff15c4e48900         call dword ptr [0x89e4c4]
// 004d0e85  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004d0e89  64890d00000000       mov dword ptr fs:[0], ecx
// 004d0e90  5e                   pop esi
// 004d0e91  83c438               add esp, 0x38
// 004d0e94  c23c00               ret 0x3c
// copied from an identical function in another client (function ?f@S@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H0@Z)

// RBX::Network::Client  0049f210  ?f@S@@QAEXUString@@H0@Z
#include <string>

struct Error {
    char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raiseError(const Error&);

typedef void (__cdecl *Callback)(void*, std::string, int, std::string);

struct CallbackTable {
    Callback unused;
    Callback invoke;
};

struct S {
    CallbackTable *table;
    unsigned int reserved;
    char context;

    void f(std::string first, int value, std::string second);
};

void S::f(std::string first, int value, std::string second) {
    if (!table)
        raiseError(Error());

    table->invoke(&context, first, value, second);
}