// from server: 100% by Xemicl
// roc 2012-06 0078cdc0  unit: RBX::VVisit::?$FactoryProduct  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0078cdc0
//
// 0078cdc0  6aff                 push -1
// 0078cdc2  68a379ab00           push 0xab79a3
// 0078cdc7  64a100000000         mov eax, dword ptr fs:[0]
// 0078cdcd  50                   push eax
// 0078cdce  64892500000000       mov dword ptr fs:[0], esp
// 0078cdd5  51                   push ecx
// 0078cdd6  56                   push esi
// 0078cdd7  6a24                 push 0x24
// 0078cdd9  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0078cde1  e834531f00           call 0x98211a
// 0078cde6  8bf0                 mov esi, eax
// 0078cde8  83c404               add esp, 4
// 0078cdeb  89742404             mov dword ptr [esp + 4], esi
// 0078cdef  c644241001           mov byte ptr [esp + 0x10], 1
// 0078cdf4  85f6                 test esi, esi
// 0078cdf6  7421                 je 0x78ce19
// 0078cdf8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078cdfc  57                   push edi
// 0078cdfd  8d4c2420             lea ecx, [esp + 0x20]
// 0078ce01  8d7e04               lea edi, [esi + 4]
// 0078ce04  51                   push ecx
// 0078ce05  8bcf                 mov ecx, edi
// 0078ce07  8906                 mov dword ptr [esi], eax
// 0078ce09  ff154426b200         call dword ptr [0xb22644]
// 0078ce0f  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0078ce13  89571c               mov dword ptr [edi + 0x1c], edx
// 0078ce16  5f                   pop edi
// 0078ce17  eb02                 jmp 0x78ce1b
// 0078ce19  33f6                 xor esi, esi
// 0078ce1b  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0078ce1f  8d4c241c             lea ecx, [esp + 0x1c]
// 0078ce23  8930                 mov dword ptr [eax], esi
// 0078ce25  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0078ce2d  ff153c26b200         call dword ptr [0xb2263c]
// 0078ce33  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0078ce37  5e                   pop esi
// 0078ce38  64890d00000000       mov dword ptr fs:[0], ecx
// 0078ce3f  83c410               add esp, 0x10
// 0078ce42  c22c00               ret 0x2c
// copied from an identical function in another client (function ??$assign_functor@UBound@function@detail@boost@@@?$basic_vtable0@X@function@detail@boost@@QAEXUBound@123@AATfunction_buffer@123@U?$bool_@$0A@@mpl@3@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost {
namespace mpl { template<bool C> struct bool_ {}; typedef bool_<false> false_; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; };
struct List2 { std::string a1_; int a2_; };
struct Bound { void (*f_)(std::string, int); List2 l_; };
template<class R> struct basic_vtable0 {
    template<class F> void assign_functor(F f, function_buffer& functor, mpl::false_) {
        functor.obj_ptr = new F(f);
    }
};
template void basic_vtable0<void>::assign_functor<Bound>(Bound, function_buffer&, mpl::false_);
}}}