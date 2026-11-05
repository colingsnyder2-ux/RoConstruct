// from server: 100% by Yeetserama
// roc 2007-08 004b0bc0  unit: RBX::Network::VReplicator::?$SignalDesc  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b0bc0
//
// 004b0bc0  6aff                 push -1
// 004b0bc2  68d98c7400           push 0x748cd9
// 004b0bc7  64a100000000         mov eax, dword ptr fs:[0]
// 004b0bcd  50                   push eax
// 004b0bce  51                   push ecx
// 004b0bcf  56                   push esi
// 004b0bd0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b0bd5  33c4                 xor eax, esp
// 004b0bd7  50                   push eax
// 004b0bd8  8d44240c             lea eax, [esp + 0xc]
// 004b0bdc  64a300000000         mov dword ptr fs:[0], eax
// 004b0be2  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004b0be6  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004b0bea  50                   push eax
// 004b0beb  83ec1c               sub esp, 0x1c
// 004b0bee  8d542440             lea edx, [esp + 0x40]
// 004b0bf2  8bcc                 mov ecx, esp
// 004b0bf4  89642428             mov dword ptr [esp + 0x28], esp
// 004b0bf8  52                   push edx
// 004b0bf9  c744243800000000     mov dword ptr [esp + 0x38], 0
// 004b0c01  ff159ce67700         call dword ptr [0x77e69c]
// 004b0c07  8bce                 mov ecx, esi
// 004b0c09  e802f3ffff           call 0x4aff10
// 004b0c0e  8d4c2420             lea ecx, [esp + 0x20]
// 004b0c12  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004b0c1a  ff15ace67700         call dword ptr [0x77e6ac]
// 004b0c20  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b0c24  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0c2b  59                   pop ecx
// 004b0c2c  5e                   pop esi
// 004b0c2d  83c410               add esp, 0x10
// 004b0c30  c3                   ret 
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
