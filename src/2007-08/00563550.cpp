// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00563550  unit: RBX::BoolPropertyVerb  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563550
//
// 00563550  83ec1c               sub esp, 0x1c
// 00563553  53                   push ebx
// 00563554  55                   push ebp
// 00563555  56                   push esi
// 00563556  57                   push edi
// 00563557  8bf9                 mov edi, ecx
// 00563559  8d7714               lea esi, [edi + 0x14]
// 0056355c  6a01                 push 1
// 0056355e  8bce                 mov ecx, esi
// 00563560  e89bedffff           call 0x562300
// 00563565  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 0056356b  8b4808               mov ecx, dword ptr [eax + 8]
// 0056356e  394804               cmp dword ptr [eax + 4], ecx
// 00563571  89442410             mov dword ptr [esp + 0x10], eax
// 00563575  894c2414             mov dword ptr [esp + 0x14], ecx
// 00563579  7606                 jbe 0x563581
// 0056357b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00563581  8b7f24               mov edi, dword ptr [edi + 0x24]
// 00563584  6a01                 push 1
// 00563586  8bce                 mov ecx, esi
// 00563588  bdf0065600           mov ebp, 0x5606f0
// 0056358d  897c2428             mov dword ptr [esp + 0x28], edi
// 00563591  e86aedffff           call 0x562300
// 00563596  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 0056359c  8b7808               mov edi, dword ptr [eax + 8]
// 0056359f  397804               cmp dword ptr [eax + 4], edi
// 005635a2  7606                 jbe 0x5635aa
// 005635a4  ff15d8e67700         call dword ptr [0x77e6d8]
// 005635aa  6a01                 push 1
// 005635ac  8bce                 mov ecx, esi
// 005635ae  e84dedffff           call 0x562300
// 005635b3  8b9804010000         mov ebx, dword ptr [eax + 0x104]
// 005635b9  8b7304               mov esi, dword ptr [ebx + 4]
// 005635bc  3b7308               cmp esi, dword ptr [ebx + 8]
// 005635bf  7606                 jbe 0x5635c7
// 005635c1  ff15d8e67700         call dword ptr [0x77e6d8]
// 005635c7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005635cb  83ec0c               sub esp, 0xc
// 005635ce  8bc4                 mov eax, esp
// 005635d0  8928                 mov dword ptr [eax], ebp
// 005635d2  894804               mov dword ptr [eax + 4], ecx
// 005635d5  89742428             mov dword ptr [esp + 0x28], esi
// 005635d9  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005635dd  57                   push edi
// 005635de  56                   push esi
// 005635df  894808               mov dword ptr [eax + 8], ecx
// 005635e2  e849ceffff           call 0x560430
// 005635e7  83c414               add esp, 0x14
// 005635ea  85db                 test ebx, ebx
// 005635ec  8bf0                 mov esi, eax
// 005635ee  7406                 je 0x5635f6
// 005635f0  3b5c2410             cmp ebx, dword ptr [esp + 0x10]
// 005635f4  7406                 je 0x5635fc
// 005635f6  ff15d8e67700         call dword ptr [0x77e6d8]
// 005635fc  5f                   pop edi
// 005635fd  33c0                 xor eax, eax
// 005635ff  3b742410             cmp esi, dword ptr [esp + 0x10]
// 00563603  5e                   pop esi
// 00563604  5d                   pop ebp
// 00563605  0f95c0               setne al
// 00563608  5b                   pop ebx
// 00563609  83c41c               add esp, 0x1c
// 0056360c  c3                   ret 
// Callee 0x560430 is the matched std::_Find_if over boost::shared_ptr<Instance>*
// with boost::bind(predicate, value, _1) (12-byte bind_t: fn, value<Instance*>, arg<1>).

#include <intrin.h>
#include <vector>
#include <algorithm>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<int I> struct arg {};
namespace _bi {
template<class T> class value {
public:
    value(T const& t) : t_(t) {}
    T& get() { return t_; }
private:
    T t_;
};
template<class A1> struct storage1 {
    explicit storage1(A1 a1) : a1_(a1) {}
    A1 a1_;
};
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
    A2 a2_;
};
template<class A1, class A2> class list2 : private storage2<A1, A2> {
    typedef storage2<A1, A2> base_type;
public:
    list2(A1 a1, A2 a2) : base_type(a1, a2) {}
    template<class R, class F, class X> R call(F& f, X& x) { return f(base_type::a1_.get(), x); }
};
template<class R, class F, class L> class bind_t {
public:
    bind_t(F f, L const& l) : f_(f), l_(l) {}
    template<class X> R operator()(X& x) { return l_.template call<R>(f_, x); }
private:
    F f_;
    L l_;
};
}
template<class R, class B1, class B2, class A1, class A2>
_bi::bind_t<R, R (*)(B1, B2), _bi::list2<_bi::value<A1>, A2> > bind(R (*f)(B1, B2), A1 a1, A2 a2)
{
    typedef _bi::list2<_bi::value<A1>, A2> list_type;
    return _bi::bind_t<R, R (*)(B1, B2), list_type>(f, list_type(a1, a2));
}
}
static boost::arg<1> _1;

namespace RBX {
class Instance;
typedef boost::shared_ptr<Instance> SharedInstance;

class Selection {
public:
    char pad[0x104];
    std::vector<SharedInstance>* selection;
};

template<class Service> class ServiceClient {
public:
    char data[0x10];
    Service* createService(bool create);
};

bool isSelected(Instance* instance, SharedInstance item);

class BoolPropertyVerb {
public:
    char pad[0x14];
    ServiceClient<Selection> selection;
    Instance* instance;
    bool isChecked();
};

bool BoolPropertyVerb::isChecked()
{
    return std::find_if(selection.createService(true)->selection->begin(),
                        selection.createService(true)->selection->end(),
                        boost::bind(&isSelected, instance, _1)) != selection.createService(true)->selection->end();
}
}
