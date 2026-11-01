// from server: 100% by Yeetserama
// roc 2007-08 0049ac60  unit: RBX::Network::VClient::?$SignalDesc  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049ac60
//
// 0049ac60  6aff                 push -1
// 0049ac62  68d98c7400           push 0x748cd9
// 0049ac67  64a100000000         mov eax, dword ptr fs:[0]
// 0049ac6d  50                   push eax
// 0049ac6e  51                   push ecx
// 0049ac6f  56                   push esi
// 0049ac70  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049ac75  33c4                 xor eax, esp
// 0049ac77  50                   push eax
// 0049ac78  8d44240c             lea eax, [esp + 0xc]
// 0049ac7c  64a300000000         mov dword ptr fs:[0], eax
// 0049ac82  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0049ac86  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0049ac8a  50                   push eax
// 0049ac8b  83ec1c               sub esp, 0x1c
// 0049ac8e  8d542440             lea edx, [esp + 0x40]
// 0049ac92  8bcc                 mov ecx, esp
// 0049ac94  89642428             mov dword ptr [esp + 0x28], esp
// 0049ac98  52                   push edx
// 0049ac99  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0049aca1  ff159ce67700         call dword ptr [0x77e69c]
// 0049aca7  8bce                 mov ecx, esi
// 0049aca9  e8e2f9ffff           call 0x49a690
// 0049acae  8d4c2420             lea ecx, [esp + 0x20]
// 0049acb2  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0049acba  ff15ace67700         call dword ptr [0x77e6ac]
// 0049acc0  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049acc4  64890d00000000       mov dword ptr fs:[0], ecx
// 0049accb  59                   pop ecx
// 0049accc  5e                   pop esi
// 0049accd  83c410               add esp, 0x10
// 0049acd0  c3                   ret 
// copied from an identical function in another client (function ?forward@ns_ROCX000003@@YAXPAUS@1@V?$basic_string@DU?$char_traits@D@std@ns_ROCX000003@@V?$allocator@D@23@@std@1@H@Z)

namespace ns_ROCX000003 {
// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string();
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}





struct S {
    void invoke(std::string, int);
};

void forward(S *object, std::string value, int argument)
{
    object->invoke(value, argument);
}
}
