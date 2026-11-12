// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00415ae0  unit: VCContent::?$CComContainedObject  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00415ae0
//
// 00415ae0  6aff                 push -1
// 00415ae2  68a9aa7300           push 0x73aaa9
// 00415ae7  64a100000000         mov eax, dword ptr fs:[0]
// 00415aed  50                   push eax
// 00415aee  51                   push ecx
// 00415aef  56                   push esi
// 00415af0  57                   push edi
// 00415af1  a188518b00           mov eax, dword ptr [0x8b5188]
// 00415af6  33c4                 xor eax, esp
// 00415af8  50                   push eax
// 00415af9  8d442410             lea eax, [esp + 0x10]
// 00415afd  64a300000000         mov dword ptr fs:[0], eax
// 00415b03  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00415b07  8bf1                 mov esi, ecx
// 00415b09  83ec1c               sub esp, 0x1c
// 00415b0c  8d442440             lea eax, [esp + 0x40]
// 00415b10  8bcc                 mov ecx, esp
// 00415b12  89642428             mov dword ptr [esp + 0x28], esp
// 00415b16  50                   push eax
// 00415b17  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00415b1f  ff159ce67700         call dword ptr [0x77e69c]
// 00415b25  8b3f                 mov edi, dword ptr [edi]
// 00415b27  8b4e04               mov ecx, dword ptr [esi + 4]
// 00415b2a  8b16                 mov edx, dword ptr [esi]
// 00415b2c  03cf                 add ecx, edi
// 00415b2e  ffd2                 call edx
// 00415b30  8d4c2424             lea ecx, [esp + 0x24]
// 00415b34  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00415b3c  ff15ace67700         call dword ptr [0x77e6ac]
// 00415b42  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00415b46  64890d00000000       mov dword ptr fs:[0], ecx
// 00415b4d  59                   pop ecx
// 00415b4e  5f                   pop edi
// 00415b4f  5e                   pop esi
// 00415b50  83c410               add esp, 0x10
// 00415b53  c22000               ret 0x20

#include <string>

// receiver class: the call adjusts this by the pmf's second word ([fn+4]),
// so the member pointer has the 8-byte multiple-inheritance representation
class __multiple_inheritance Content;

inline Content* get_pointer(Content* p) { return p; }

// boost::_mfi::mf1-shaped functor
struct ContentCall {
    void (Content::*f)(std::string);
    template <class U, class B1> void call(U& u, void const*, B1& b1) const
    {
        (get_pointer(u)->*f)(b1);
    }
    template <class U> void operator()(U& u, std::string a1) const
    {
        call(u, &u, a1);
    }
};

template void ContentCall::operator()<Content* const>(Content* const&, std::string) const;
