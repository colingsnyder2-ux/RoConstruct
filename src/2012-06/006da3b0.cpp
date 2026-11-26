// from server: 100% by Xemicl
// roc 2012-06 006da3b0  unit: RBX::DataModel::W4GearType::?$EnumDesc  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006da3b0
//
// 006da3b0  6aff                 push -1
// 006da3b2  6828b3ab00           push 0xabb328
// 006da3b7  64a100000000         mov eax, dword ptr fs:[0]
// 006da3bd  50                   push eax
// 006da3be  64892500000000       mov dword ptr fs:[0], esp
// 006da3c5  51                   push ecx
// 006da3c6  56                   push esi
// 006da3c7  8bf1                 mov esi, ecx
// 006da3c9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006da3cd  8d4608               lea eax, [esi + 8]
// 006da3d0  50                   push eax
// 006da3d1  83ec3c               sub esp, 0x3c
// 006da3d4  8bc4                 mov eax, esp
// 006da3d6  8d54245c             lea edx, [esp + 0x5c]
// 006da3da  89642444             mov dword ptr [esp + 0x44], esp
// 006da3de  8908                 mov dword ptr [eax], ecx
// 006da3e0  8d4804               lea ecx, [eax + 4]
// 006da3e3  52                   push edx
// 006da3e4  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006da3ec  e81f77ffff           call 0x6d1b10
// 006da3f1  b91c56da00           mov ecx, 0xda561c
// 006da3f6  e8c5ddffff           call 0x6d81c0
// 006da3fb  0fb6c0               movzx eax, al
// 006da3fe  f7d8                 neg eax
// 006da400  1bc0                 sbb eax, eax
// 006da402  251c56da00           and eax, 0xda561c
// 006da407  8d4c241c             lea ecx, [esp + 0x1c]
// 006da40b  8906                 mov dword ptr [esi], eax
// 006da40d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006da415  e8f66affff           call 0x6d0f10
// 006da41a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006da41e  64890d00000000       mov dword ptr fs:[0], ecx
// 006da425  5e                   pop esi
// 006da426  83c410               add esp, 0x10
// 006da429  c23c00               ret 0x3c
// copied from an identical function in another client (function ??$assign_to@U?$bind_t@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@P6A?AV12@V12@0@ZU?$list1@US2@_bi@boost@@@_bi@boost@@@_bi@boost@@@?$function0@XV?$allocator@H@std@@@boost@@QAEXU?$bind_t@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@P6A?AV12@V12@0@ZU?$list1@US2@_bi@boost@@@_bi@boost@@@_bi@1@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
namespace _bi {
template<class T> struct value { T t_; };
struct S2 { std::string a, b; S2(const S2&); ~S2(); };
template<class A1> struct list1 { A1 a1_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; double d; };
struct vtable_base { void* manager; };
template<class R, class Alloc> struct basic_vtable0 {
    vtable_base base;
    void* invoker;
    template<class F> bool assign_to(F f, function_buffer& functor);
};
}}
template<class R, class Alloc = std::allocator<int> > class function0 {
public:
    typedef detail::function::basic_vtable0<R, Alloc> vtable_type;
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
    template<class Functor> void assign_to(Functor f) {
        static vtable_type stored_vtable = { { 0 }, 0 };
        if (stored_vtable.assign_to(f, functor)) vtable = &stored_vtable.base;
        else vtable = 0;
    }
};
typedef _bi::bind_t<std::string, std::string (*)(std::string, std::string), _bi::list1<_bi::S2> > B;
template void function0<void>::assign_to<B>(B);
}