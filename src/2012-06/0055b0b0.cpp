// from server: 100% by Xemicl
// roc 2012-06 0055b0b0  unit: RBX::Network::VClient::?$FactoryProduct  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0055b0b0
//
// 0055b0b0  6aff                 push -1
// 0055b0b2  68b331ac00           push 0xac31b3
// 0055b0b7  64a100000000         mov eax, dword ptr fs:[0]
// 0055b0bd  50                   push eax
// 0055b0be  64892500000000       mov dword ptr fs:[0], esp
// 0055b0c5  83ec2c               sub esp, 0x2c
// 0055b0c8  56                   push esi
// 0055b0c9  8bf1                 mov esi, ecx
// 0055b0cb  833e00               cmp dword ptr [esi], 0
// 0055b0ce  c744243801000000     mov dword ptr [esp + 0x38], 1
// 0055b0d6  7514                 jne 0x55b0ec
// 0055b0d8  8d4c2408             lea ecx, [esp + 8]
// 0055b0dc  e8ff11ebff           call 0x40c2e0
// 0055b0e1  50                   push eax
// 0055b0e2  c644243c02           mov byte ptr [esp + 0x3c], 2
// 0055b0e7  e8d443ebff           call 0x40f4c0
// 0055b0ec  83ec1c               sub esp, 0x1c
// 0055b0ef  8d44247c             lea eax, [esp + 0x7c]
// 0055b0f3  8bcc                 mov ecx, esp
// 0055b0f5  89642420             mov dword ptr [esp + 0x20], esp
// 0055b0f9  50                   push eax
// 0055b0fa  ff154426b200         call dword ptr [0xb22644]
// 0055b100  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0055b104  51                   push ecx
// 0055b105  83ec1c               sub esp, 0x1c
// 0055b108  8d54247c             lea edx, [esp + 0x7c]
// 0055b10c  8bcc                 mov ecx, esp
// 0055b10e  89a42498000000       mov dword ptr [esp + 0x98], esp
// 0055b115  52                   push edx
// 0055b116  c644247803           mov byte ptr [esp + 0x78], 3
// 0055b11b  ff154426b200         call dword ptr [0xb22644]
// 0055b121  8b06                 mov eax, dword ptr [esi]
// 0055b123  83c608               add esi, 8
// 0055b126  c644247401           mov byte ptr [esp + 0x74], 1
// 0055b12b  8b4004               mov eax, dword ptr [eax + 4]
// 0055b12e  56                   push esi
// 0055b12f  ffd0                 call eax
// 0055b131  83c440               add esp, 0x40
// 0055b134  8d4c2440             lea ecx, [esp + 0x40]
// 0055b138  c644243800           mov byte ptr [esp + 0x38], 0
// 0055b13d  ff153c26b200         call dword ptr [0xb2263c]
// 0055b143  8d4c2460             lea ecx, [esp + 0x60]
// 0055b147  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0055b14f  ff153c26b200         call dword ptr [0xb2263c]
// 0055b155  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0055b159  64890d00000000       mov dword ptr fs:[0], ecx
// 0055b160  5e                   pop esi
// 0055b161  83c438               add esp, 0x38
// 0055b164  c23c00               ret 0x3c
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