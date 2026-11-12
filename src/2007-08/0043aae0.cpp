// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0043aae0  unit: CSelectionPropGrid  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043aae0
//
// 0043aae0  83ec0c               sub esp, 0xc
// 0043aae3  53                   push ebx
// 0043aae4  55                   push ebp
// 0043aae5  56                   push esi
// 0043aae6  57                   push edi
// 0043aae7  8bf1                 mov esi, ecx
// 0043aae9  8d442420             lea eax, [esp + 0x20]
// 0043aaed  50                   push eax
// 0043aaee  8d4e04               lea ecx, [esi + 4]
// 0043aaf1  e8caa30200           call 0x464ec0
// 0043aaf6  8bee                 mov ebp, esi
// 0043aaf8  8b742420             mov esi, dword ptr [esp + 0x20]
// 0043aafc  8b7e7c               mov edi, dword ptr [esi + 0x7c]
// 0043aaff  83c674               add esi, 0x74
// 0043ab02  397e04               cmp dword ptr [esi + 4], edi
// 0043ab05  bbe0aa4300           mov ebx, 0x43aae0
// 0043ab0a  7606                 jbe 0x43ab12
// 0043ab0c  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043ab12  8b5604               mov edx, dword ptr [esi + 4]
// 0043ab15  3b5608               cmp edx, dword ptr [esi + 8]
// 0043ab18  89542420             mov dword ptr [esp + 0x20], edx
// 0043ab1c  760a                 jbe 0x43ab28
// 0043ab1e  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043ab24  8b542420             mov edx, dword ptr [esp + 0x20]
// 0043ab28  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043ab2c  83ec0c               sub esp, 0xc
// 0043ab2f  8bc4                 mov eax, esp
// 0043ab31  57                   push edi
// 0043ab32  56                   push esi
// 0043ab33  8918                 mov dword ptr [eax], ebx
// 0043ab35  52                   push edx
// 0043ab36  896804               mov dword ptr [eax + 4], ebp
// 0043ab39  894808               mov dword ptr [eax + 8], ecx
// 0043ab3c  8d4c2428             lea ecx, [esp + 0x28]
// 0043ab40  56                   push esi
// 0043ab41  51                   push ecx
// 0043ab42  e839f5ffff           call 0x43a080
// 0043ab47  83c420               add esp, 0x20
// 0043ab4a  5f                   pop edi
// 0043ab4b  5e                   pop esi
// 0043ab4c  5d                   pop ebp
// 0043ab4d  5b                   pop ebx
// 0043ab4e  83c40c               add esp, 0xc
// roc-cl: 50727
#include <vector>
#include <algorithm>

namespace boost {
template<int I> struct arg {};
namespace _mfi {
template<class R, class T, class A1> class mf1 {
    typedef R (T::*F)(A1);
    F f_;
public:
    explicit mf1(F f) : f_(f) {}
    R operator()(T* p, A1 a1) const { return (p->*f_)(a1); }
};
}
namespace _bi {
template<class T> class value {
public:
    value(T const& t) : t_(t) {}
    T& get() { return t_; }
private:
    T t_;
};
template<class A1, class A2> class list2 {
public:
    list2(A1 a1, A2 a2) : a1_(a1), a2_(a2) {}
    A1 a1_;
    A2 a2_;
};
template<class R, class F, class L> class bind_t {
public:
    bind_t(F f, L const& l) : f_(f), l_(l) {}
    template<class X> R operator()(X& x) { return f_(l_.a1_.get(), x); }
    F f_;
    L l_;
};
}
template<class R, class T, class B1, class A1, class A2>
_bi::bind_t<R, _mfi::mf1<R, T, B1>, _bi::list2<_bi::value<A1>, arg<1> > >
bind(R (T::*f)(B1), A1 a1, A2 a2)
{
    typedef _mfi::mf1<R, T, B1> F;
    typedef _bi::list2<_bi::value<A1>, arg<1> > L;
    return _bi::bind_t<R, F, L>(F(f), L(a1, a2));
}
}
static boost::arg<1> _1;

class Instance {
public:
    char pad[0x74];
    std::vector<Instance*> children;
};

class CSelectionPropGrid {
public:
    void* vftable;
    std::vector<Instance*> items;
    void addRecursive(Instance* x);
};

void CSelectionPropGrid::addRecursive(Instance* x)
{
    items.push_back(x);
    std::for_each(x->children.begin(), x->children.end(), boost::bind(&CSelectionPropGrid::addRecursive, this, _1));
}
