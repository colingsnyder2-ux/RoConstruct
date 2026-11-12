// from server: 100% by EspClaude
// from server: 54% by tester
// roc 2007-08 0043a000  unit: RBX::VSoundId::?$XItem  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a000
//
// 0043a000  83ec08               sub esp, 8
// 0043a003  53                   push ebx
// 0043a004  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0043a008  55                   push ebp
// 0043a009  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0043a00d  56                   push esi
// 0043a00e  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0043a012  57                   push edi
// 0043a013  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043a017  89742410             mov dword ptr [esp + 0x10], esi
// 0043a01b  897c2414             mov dword ptr [esp + 0x14], edi
// 0043a01f  90                   nop 
// 0043a020  85f6                 test esi, esi
// 0043a022  7406                 je 0x43a02a
// 0043a024  3b742428             cmp esi, dword ptr [esp + 0x28]
// 0043a028  7406                 je 0x43a030
// 0043a02a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043a030  3b7c242c             cmp edi, dword ptr [esp + 0x2c]
// 0043a034  742e                 je 0x43a064
// 0043a036  85f6                 test esi, esi
// 0043a038  7506                 jne 0x43a040
// 0043a03a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043a040  3b7e04               cmp edi, dword ptr [esi + 4]
// 0043a043  7506                 jne 0x43a04b
// 0043a045  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043a04b  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0043a04e  53                   push ebx
// 0043a04f  ffd5                 call ebp
// 0043a051  8d4c2410             lea ecx, [esp + 0x10]
// 0043a055  e8e6d11e00           call 0x627240
// 0043a05a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0043a05e  8b742410             mov esi, dword ptr [esp + 0x10]
// 0043a062  ebbc                 jmp 0x43a020
// 0043a064  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043a068  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0043a06c  5f                   pop edi
// 0043a06d  8928                 mov dword ptr [eax], ebp
// 0043a06f  5e                   pop esi
// 0043a070  894804               mov dword ptr [eax + 4], ecx
// 0043a073  5d                   pop ebp
// 0043a074  895808               mov dword ptr [eax + 8], ebx
// 0043a077  5b                   pop ebx
// 0043a078  83c408               add esp, 8
// 0043a07b  c3                   ret 
#include <set>
#include <algorithm>

struct A;
struct X { void f(A* a); };

namespace bnd {
struct arg1 {};
template<class T> struct value { T t_; };
struct mf1 {
    void (X::*f_)(A*);
    void operator()(X* p, A* a) const { (p->*f_)(a); }
};
struct list2 {
    arg1 a1_;
    value<A*> a2_;
};
struct bind_t {
    mf1 f_;
    list2 l_;
    void operator()(X* p) { f_(p, l_.a2_.t_); }
};
}

template bnd::bind_t std::for_each(std::set<X*>::iterator, std::set<X*>::iterator, bnd::bind_t);
