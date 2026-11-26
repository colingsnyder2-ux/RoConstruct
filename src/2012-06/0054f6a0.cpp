// from server: 100% by Xemicl
// roc 2012-06 0054f6a0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0054f6a0
//
// 0054f6a0  6aff                 push -1
// 0054f6a2  6888d1aa00           push 0xaad188
// 0054f6a7  64a100000000         mov eax, dword ptr fs:[0]
// 0054f6ad  50                   push eax
// 0054f6ae  64892500000000       mov dword ptr fs:[0], esp
// 0054f6b5  51                   push ecx
// 0054f6b6  56                   push esi
// 0054f6b7  57                   push edi
// 0054f6b8  8bf1                 mov esi, ecx
// 0054f6ba  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054f6be  83ec58               sub esp, 0x58
// 0054f6c1  8bc4                 mov eax, esp
// 0054f6c3  c70600000000         mov dword ptr [esi], 0
// 0054f6c9  8908                 mov dword ptr [eax], ecx
// 0054f6cb  8b542478             mov edx, dword ptr [esp + 0x78]
// 0054f6cf  8d7808               lea edi, [eax + 8]
// 0054f6d2  895004               mov dword ptr [eax + 4], edx
// 0054f6d5  8d44247c             lea eax, [esp + 0x7c]
// 0054f6d9  89642460             mov dword ptr [esp + 0x60], esp
// 0054f6dd  50                   push eax
// 0054f6de  8bcf                 mov ecx, edi
// 0054f6e0  c744247000000000     mov dword ptr [esp + 0x70], 0
// 0054f6e8  e8236cffff           call 0x546310
// 0054f6ed  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 0054f6f4  894f48               mov dword ptr [edi + 0x48], ecx
// 0054f6f7  8bce                 mov ecx, esi
// 0054f6f9  e872e4ffff           call 0x54db70
// 0054f6fe  8d4c2424             lea ecx, [esp + 0x24]
// 0054f702  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0054f70a  e82167ffff           call 0x545e30
// 0054f70f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054f713  5f                   pop edi
// 0054f714  8bc6                 mov eax, esi
// 0054f716  64890d00000000       mov dword ptr fs:[0], ecx
// 0054f71d  5e                   pop esi
// 0054f71e  83c410               add esp, 0x10
// 0054f721  c25c00               ret 0x5c
// copied from an identical function in another client (function ??$?0U?$bind_t@XUPair8@@UL2@@@_bi@boost@@@?$function0@X@boost@@QAE@U?$bind_t@XUPair8@@UL2@@@_bi@1@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Network { class Players; } }
struct Arg48 { double d; char pad[0x40]; Arg48(const Arg48&); ~Arg48(); };
namespace boost {
namespace _mfi { template<class R, class T, class A1, class A2> struct mf2 { R (T::*f_)(A1, A2); }; }
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2, class A3> struct list3 { A1 a1_; A2 a2_; A3 a3_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[8]; double d; };
struct vtable_base { void* manager; };
}}
template<class R> class function0 {
public:
    detail::function::vtable_base* vtable;
    detail::function::function_buffer functor;
    template<class Functor> function0(Functor f, int = 0) : vtable(0) { this->assign_to(f); }
    template<class Functor> void assign_to(Functor f);
};
}
struct Pair8 { int a, b; };
struct L2 { Arg48 a1_; int a2_; };
typedef boost::_bi::bind_t<void, Pair8, L2> B;
template boost::function0<void>::function0(B, int);