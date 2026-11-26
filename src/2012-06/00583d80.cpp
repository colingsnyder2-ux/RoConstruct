// from server: 100% by Xemicl
// roc 2012-06 00583d80  unit: RBX::Network::Replicator  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00583d80
//
// 00583d80  6aff                 push -1
// 00583d82  6891a9ac00           push 0xaca991
// 00583d87  64a100000000         mov eax, dword ptr fs:[0]
// 00583d8d  50                   push eax
// 00583d8e  64892500000000       mov dword ptr fs:[0], esp
// 00583d95  83ec28               sub esp, 0x28
// 00583d98  56                   push esi
// 00583d99  8bf1                 mov esi, ecx
// 00583d9b  833e00               cmp dword ptr [esi], 0
// 00583d9e  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00583da6  7514                 jne 0x583dbc
// 00583da8  8d4c2404             lea ecx, [esp + 4]
// 00583dac  e82f85e8ff           call 0x40c2e0
// 00583db1  50                   push eax
// 00583db2  c644243801           mov byte ptr [esp + 0x38], 1
// 00583db7  e804b7e8ff           call 0x40f4c0
// 00583dbc  8b442458             mov eax, dword ptr [esp + 0x58]
// 00583dc0  50                   push eax
// 00583dc1  83ec1c               sub esp, 0x1c
// 00583dc4  8d54245c             lea edx, [esp + 0x5c]
// 00583dc8  8bcc                 mov ecx, esp
// 00583dca  89642478             mov dword ptr [esp + 0x78], esp
// 00583dce  52                   push edx
// 00583dcf  ff154426b200         call dword ptr [0xb22644]
// 00583dd5  8b06                 mov eax, dword ptr [esi]
// 00583dd7  8b4804               mov ecx, dword ptr [eax + 4]
// 00583dda  83c608               add esi, 8
// 00583ddd  56                   push esi
// 00583dde  ffd1                 call ecx
// 00583de0  83c424               add esp, 0x24
// 00583de3  8d4c243c             lea ecx, [esp + 0x3c]
// 00583de7  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 00583def  ff153c26b200         call dword ptr [0xb2263c]
// 00583df5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00583df9  64890d00000000       mov dword ptr fs:[0], ecx
// 00583e00  5e                   pop esi
// 00583e01  83c434               add esp, 0x34
// 00583e04  c22000               ret 0x20
// copied from an identical function in another client (function ?invoke@S@ns_ROCX00009c@@QAEXV?$basic_string@DU?$char_traits@D@std@ns_ROCX00009c@@V?$allocator@D@23@@std@2@H@Z)

namespace ns_ROCX00009c {
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}



struct ExceptionObject {
    unsigned long words[10];

    ExceptionObject();
    ~ExceptionObject();
};

extern __declspec(noreturn) void __cdecl raise_exception(const void*);

struct Dispatch {
    void* reserved;
    void (__cdecl *invoke)(void*, std::string, int);
};

struct S {
    Dispatch* dispatch;
    unsigned long reserved;
    unsigned char object[1];

    void invoke(std::string value, int argument);
};

void S::invoke(std::string value, int argument)
{
    if (!dispatch)
        raise_exception(&ExceptionObject());

    dispatch->invoke(object, value, argument);
}
}