// from server: 100% by Yeetserama
// roc 2007-08 00419680  unit: VDHTMLWindowService::?$FactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00419680
//
// 00419680  6aff                 push -1
// 00419682  68d98c7400           push 0x748cd9
// 00419687  64a100000000         mov eax, dword ptr fs:[0]
// 0041968d  50                   push eax
// 0041968e  51                   push ecx
// 0041968f  56                   push esi
// 00419690  a188518b00           mov eax, dword ptr [0x8b5188]
// 00419695  33c4                 xor eax, esp
// 00419697  50                   push eax
// 00419698  8d44240c             lea eax, [esp + 0xc]
// 0041969c  64a300000000         mov dword ptr fs:[0], eax
// 004196a2  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004196a6  83ec1c               sub esp, 0x1c
// 004196a9  8d44243c             lea eax, [esp + 0x3c]
// 004196ad  8bcc                 mov ecx, esp
// 004196af  89642424             mov dword ptr [esp + 0x24], esp
// 004196b3  50                   push eax
// 004196b4  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004196bc  ff159ce67700         call dword ptr [0x77e69c]
// 004196c2  8bce                 mov ecx, esi
// 004196c4  e817f4ffff           call 0x418ae0
// 004196c9  8d4c2420             lea ecx, [esp + 0x20]
// 004196cd  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004196d5  ff15ace67700         call dword ptr [0x77e6ac]
// 004196db  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004196df  64890d00000000       mov dword ptr fs:[0], ecx
// 004196e6  59                   pop ecx
// 004196e7  5e                   pop esi
// 004196e8  83c410               add esp, 0x10
// 004196eb  c3                   ret 
// copied from an identical function in another client (function ?wrapper@ns_ROCX000001@@YAXPAUS@1@V?$basic_string@DU?$char_traits@D@std@ns_ROCX000001@@V?$allocator@D@23@@std@1@@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        __declspec(dllimport) basic_string(const basic_string&);
        __declspec(dllimport) ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct S {
    void f(std::string value);
};

void wrapper(S* object, std::string value)
{
    object->f(value);
}
}
