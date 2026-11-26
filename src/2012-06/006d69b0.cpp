// from server: 100% by Xemicl
// roc 2012-06 006d69b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d69b0
//
// 006d69b0  6aff                 push -1
// 006d69b2  6888afab00           push 0xabaf88
// 006d69b7  64a100000000         mov eax, dword ptr fs:[0]
// 006d69bd  50                   push eax
// 006d69be  64892500000000       mov dword ptr fs:[0], esp
// 006d69c5  51                   push ecx
// 006d69c6  56                   push esi
// 006d69c7  8bf1                 mov esi, ecx
// 006d69c9  8b442444             mov eax, dword ptr [esp + 0x44]
// 006d69cd  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 006d69d1  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 006d69d5  50                   push eax
// 006d69d6  51                   push ecx
// 006d69d7  52                   push edx
// 006d69d8  83ec1c               sub esp, 0x1c
// 006d69db  8d442448             lea eax, [esp + 0x48]
// 006d69df  8964242c             mov dword ptr [esp + 0x2c], esp
// 006d69e3  8bcc                 mov ecx, esp
// 006d69e5  50                   push eax
// 006d69e6  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 006d69ee  ff154426b200         call dword ptr [0xb22644]
// 006d69f4  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 006d69f8  8b542440             mov edx, dword ptr [esp + 0x40]
// 006d69fc  51                   push ecx
// 006d69fd  52                   push edx
// 006d69fe  8bce                 mov ecx, esi
// 006d6a00  e8ebe5ffff           call 0x6d4ff0
// 006d6a05  8d4c2420             lea ecx, [esp + 0x20]
// 006d6a09  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006d6a11  ff153c26b200         call dword ptr [0xb2263c]
// 006d6a17  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d6a1b  8bc6                 mov eax, esi
// 006d6a1d  64890d00000000       mov dword ptr fs:[0], ecx
// 006d6a24  5e                   pop esi
// 006d6a25  83c410               add esp, 0x10
// 006d6a28  c23000               ret 0x30
// copied from an identical function in another client (function ??0?$list5@V?$value@PAVInstance@RBX@@@_bi@boost@@U?$arg@$00@3@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@V?$value@N@23@V?$value@H@23@@_bi@boost@@QAE@V?$value@PAVInstance@RBX@@@12@U?$arg@$00@2@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@12@V?$value@N@12@V?$value@H@12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<int I> struct arg {};
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { explicit storage1(A1 a1) : a1_(a1) {} A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {} A2 a2_; };
template<class A1, int I> struct storage2<A1, boost::arg<I> > : public storage1<A1> { storage2(A1 a1, boost::arg<I>) : storage1<A1>(a1) {} };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> { storage3(A1 a1, A2 a2, A3 a3); A3 a3_; };
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> { storage4(A1 a1, A2 a2, A3 a3, A4 a4); A4 a4_; };
template<class A1, class A2, class A3, class A4, class A5> struct storage5 : public storage4<A1, A2, A3, A4> { storage5(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5); A5 a5_; };
template<class A1, class A2, class A3, class A4, class A5> class list5 : private storage5<A1, A2, A3, A4, A5> {
	typedef storage5<A1, A2, A3, A4, A5> base_type;
public:
	list5(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : base_type(a1, a2, a3, a4, a5) {}
};
}
}
namespace RBX { class Instance; }
template class boost::_bi::list5<boost::_bi::value<RBX::Instance*>, boost::arg<1>, boost::_bi::value<std::string>, boost::_bi::value<double>, boost::_bi::value<int> >;