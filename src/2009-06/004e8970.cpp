// from server: 100% by EspClaude
// roc 2009-06 004e8970  unit: RBX::JointsService  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8970
//
// 004e8970  6aff                 push -1
// 004e8972  6811ae8500           push 0x85ae11
// 004e8977  64a100000000         mov eax, dword ptr fs:[0]
// 004e897d  50                   push eax
// 004e897e  64892500000000       mov dword ptr fs:[0], esp
// 004e8985  83ec28               sub esp, 0x28
// 004e8988  56                   push esi
// 004e8989  8bf1                 mov esi, ecx
// 004e898b  833e00               cmp dword ptr [esi], 0
// 004e898e  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004e8996  7514                 jne 0x4e89ac
// 004e8998  8d4c2404             lea ecx, [esp + 4]
// 004e899c  e83f0bf2ff           call 0x4094e0
// 004e89a1  50                   push eax
// 004e89a2  c644243801           mov byte ptr [esp + 0x38], 1
// 004e89a7  e8b418f2ff           call 0x40a260
// 004e89ac  8b442458             mov eax, dword ptr [esp + 0x58]
// 004e89b0  50                   push eax
// 004e89b1  83ec1c               sub esp, 0x1c
// 004e89b4  8d54245c             lea edx, [esp + 0x5c]
// 004e89b8  8bcc                 mov ecx, esp
// 004e89ba  89642478             mov dword ptr [esp + 0x78], esp
// 004e89be  52                   push edx
// 004e89bf  ff15b8e48900         call dword ptr [0x89e4b8]
// 004e89c5  8b06                 mov eax, dword ptr [esi]
// 004e89c7  8b4804               mov ecx, dword ptr [eax + 4]
// 004e89ca  83c608               add esi, 8
// 004e89cd  56                   push esi
// 004e89ce  ffd1                 call ecx
// 004e89d0  83c424               add esp, 0x24
// 004e89d3  8d4c243c             lea ecx, [esp + 0x3c]
// 004e89d7  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 004e89df  ff15c4e48900         call dword ptr [0x89e4c4]
// 004e89e5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004e89e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004e89f0  5e                   pop esi
// 004e89f1  83c434               add esp, 0x34
// 004e89f4  c22000               ret 0x20
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
