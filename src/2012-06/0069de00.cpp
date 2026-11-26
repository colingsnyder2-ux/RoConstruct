// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 007e9e00  unit: RBX::VUDim2::?$TypedPropertyDescriptor  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e9e00
//
// 007e9e00  6aff                 push -1
// 007e9e02  68a394ac00           push 0xac94a3
// 007e9e07  64a100000000         mov eax, dword ptr fs:[0]
// 007e9e0d  50                   push eax
// 007e9e0e  64892500000000       mov dword ptr fs:[0], esp
// 007e9e15  51                   push ecx
// 007e9e16  56                   push esi
// 007e9e17  6a28                 push 0x28
// 007e9e19  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007e9e21  e8f4821900           call 0x98211a
// 007e9e26  8bf0                 mov esi, eax
// 007e9e28  83c404               add esp, 4
// 007e9e2b  89742404             mov dword ptr [esp + 4], esi
// 007e9e2f  c644241001           mov byte ptr [esp + 0x10], 1
// 007e9e34  85f6                 test esi, esi
// 007e9e36  7415                 je 0x7e9e4d
// 007e9e38  8b442418             mov eax, dword ptr [esp + 0x18]
// 007e9e3c  8d54241c             lea edx, [esp + 0x1c]
// 007e9e40  8d4e04               lea ecx, [esi + 4]
// 007e9e43  52                   push edx
// 007e9e44  8906                 mov dword ptr [esi], eax
// 007e9e46  e825ea0800           call 0x878870
// 007e9e4b  eb02                 jmp 0x7e9e4f
// 007e9e4d  33f6                 xor esi, esi
// 007e9e4f  8b442440             mov eax, dword ptr [esp + 0x40]
// 007e9e53  8d4c241c             lea ecx, [esp + 0x1c]
// 007e9e57  8930                 mov dword ptr [eax], esi
// 007e9e59  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 007e9e61  e8aae4ffff           call 0x7e8310
// 007e9e66  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e9e6a  5e                   pop esi
// 007e9e6b  64890d00000000       mov dword ptr fs:[0], ecx
// 007e9e72  83c410               add esp, 0x10
// 007e9e75  c23000               ret 0x30

// copied from an identical function in another client (function ??$assign_functor@UBound@function@detail@boost@@@?$basic_vtable0@X@function@detail@boost@@QAEXUBound@123@AATfunction_buffer@123@U?$bool_@$0A@@mpl@3@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace mpl { template<bool C> struct bool_ {}; typedef bool_<false> false_; }
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; };
struct Member { char d[0x18]; Member(const Member&); ~Member(); };
struct List { Member a1_; };
struct Bound { void* f_; List l_; };
template<class R> struct basic_vtable0 {
    template<class FunctionObj> void assign_functor(FunctionObj f, function_buffer& functor, mpl::false_) {
        functor.obj_ptr = new FunctionObj(f);
    }
};
template void basic_vtable0<void>::assign_functor<Bound>(Bound, function_buffer&, mpl::false_);
}}}
