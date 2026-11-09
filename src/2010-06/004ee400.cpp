// from server: 100% by Yeetserama
// roc 2010-06 004ee400  unit: RBX::Network::Replicator::NewInstanceItem  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ee400
//
// 004ee400  6aff                 push -1
// 004ee402  68812b9800           push 0x982b81
// 004ee407  64a100000000         mov eax, dword ptr fs:[0]
// 004ee40d  50                   push eax
// 004ee40e  64892500000000       mov dword ptr fs:[0], esp
// 004ee415  83ec28               sub esp, 0x28
// 004ee418  56                   push esi
// 004ee419  8bf1                 mov esi, ecx
// 004ee41b  833e00               cmp dword ptr [esi], 0
// 004ee41e  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004ee426  7514                 jne 0x4ee43c
// 004ee428  8d4c2404             lea ecx, [esp + 4]
// 004ee42c  e84fb0f1ff           call 0x409480
// 004ee431  50                   push eax
// 004ee432  c644243801           mov byte ptr [esp + 0x38], 1
// 004ee437  e894c0f1ff           call 0x40a4d0
// 004ee43c  8b442458             mov eax, dword ptr [esp + 0x58]
// 004ee440  50                   push eax
// 004ee441  83ec1c               sub esp, 0x1c
// 004ee444  8d54245c             lea edx, [esp + 0x5c]
// 004ee448  8bcc                 mov ecx, esp
// 004ee44a  89642478             mov dword ptr [esp + 0x78], esp
// 004ee44e  52                   push edx
// 004ee44f  ff150ca49e00         call dword ptr [0x9ea40c]
// 004ee455  8b06                 mov eax, dword ptr [esi]
// 004ee457  8b4804               mov ecx, dword ptr [eax + 4]
// 004ee45a  83c608               add esi, 8
// 004ee45d  56                   push esi
// 004ee45e  ffd1                 call ecx
// 004ee460  83c424               add esp, 0x24
// 004ee463  8d4c243c             lea ecx, [esp + 0x3c]
// 004ee467  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 004ee46f  ff1500a49e00         call dword ptr [0x9ea400]
// 004ee475  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004ee479  64890d00000000       mov dword ptr fs:[0], ecx
// 004ee480  5e                   pop esi
// 004ee481  83c434               add esp, 0x34
// 004ee484  c22000               ret 0x20
// copied from an identical function in another client (function ?invoke@S@ns_ROCX000012@@QAEXV?$basic_string@DU?$char_traits@D@std@ns_ROCX000012@@V?$allocator@D@23@@std@2@H@Z)

namespace ns_ROCX000012 {
// from server: 100% by colin
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
