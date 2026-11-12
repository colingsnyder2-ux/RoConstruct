// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00422b60  unit: CRobloxTreeCtrlNode  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00422b60
//
// 00422b60  83ec14               sub esp, 0x14
// 00422b63  8b442418             mov eax, dword ptr [esp + 0x18]
// 00422b67  53                   push ebx
// 00422b68  55                   push ebp
// 00422b69  56                   push esi
// 00422b6a  8bf1                 mov esi, ecx
// 00422b6c  50                   push eax
// 00422b6d  8d4c2414             lea ecx, [esp + 0x14]
// 00422b71  51                   push ecx
// 00422b72  e8f9aa0700           call 0x49d670
// 00422b77  8bae04010000         mov ebp, dword ptr [esi + 0x104]
// 00422b7d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00422b81  8b4508               mov eax, dword ptr [ebp + 8]
// 00422b84  83c408               add esp, 8
// 00422b87  394504               cmp dword ptr [ebp + 4], eax
// 00422b8a  8944240c             mov dword ptr [esp + 0xc], eax
// 00422b8e  7606                 jbe 0x422b96
// 00422b90  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422b96  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 00422b9c  8b5808               mov ebx, dword ptr [eax + 8]
// 00422b9f  395804               cmp dword ptr [eax + 4], ebx
// 00422ba2  7606                 jbe 0x422baa
// 00422ba4  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422baa  57                   push edi
// 00422bab  8bbe04010000         mov edi, dword ptr [esi + 0x104]
// 00422bb1  8b7704               mov esi, dword ptr [edi + 4]
// 00422bb4  3b7708               cmp esi, dword ptr [edi + 8]
// 00422bb7  7606                 jbe 0x422bbf
// 00422bb9  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422bbf  3bf3                 cmp esi, ebx
// 00422bc1  89742420             mov dword ptr [esp + 0x20], esi
// 00422bc5  7414                 je 0x422bdb
// 00422bc7  8b542428             mov edx, dword ptr [esp + 0x28]
// 00422bcb  8b02                 mov eax, dword ptr [edx]
// 00422bcd  8d4900               lea ecx, [ecx]
// 00422bd0  3906                 cmp dword ptr [esi], eax
// 00422bd2  7407                 je 0x422bdb
// 00422bd4  83c608               add esi, 8
// 00422bd7  3bf3                 cmp esi, ebx
// 00422bd9  75f5                 jne 0x422bd0
// 00422bdb  85ff                 test edi, edi
// 00422bdd  7404                 je 0x422be3
// 00422bdf  3bfd                 cmp edi, ebp
// 00422be1  7406                 je 0x422be9
// 00422be3  ff15d8e67700         call dword ptr [0x77e6d8]
// 00422be9  3b742410             cmp esi, dword ptr [esp + 0x10]
// 00422bed  8b742418             mov esi, dword ptr [esp + 0x18]
// 00422bf1  0f95c3               setne bl
// 00422bf4  85f6                 test esi, esi
// 00422bf6  5f                   pop edi
// 00422bf7  742a                 je 0x422c23
// 00422bf9  8d4604               lea eax, [esi + 4]
// 00422bfc  83c9ff               or ecx, 0xffffffff
// 00422bff  f00fc108             lock xadd dword ptr [eax], ecx
// 00422c03  751e                 jne 0x422c23
// 00422c05  8b16                 mov edx, dword ptr [esi]
// 00422c07  8b4204               mov eax, dword ptr [edx + 4]
// 00422c0a  8bce                 mov ecx, esi
// 00422c0c  ffd0                 call eax
// 00422c0e  8d4e08               lea ecx, [esi + 8]
// 00422c11  83caff               or edx, 0xffffffff
// 00422c14  f00fc111             lock xadd dword ptr [ecx], edx
// 00422c18  7509                 jne 0x422c23
// 00422c1a  8b06                 mov eax, dword ptr [esi]
// 00422c1c  8b5008               mov edx, dword ptr [eax + 8]
// 00422c1f  8bce                 mov ecx, esi
// 00422c21  ffd2                 call edx
// 00422c23  5e                   pop esi
// 00422c24  5d                   pop ebp
// 00422c25  8ac3                 mov al, bl
// 00422c27  5b                   pop ebx
// 00422c28  83c414               add esp, 0x14
// 00422c2b  c20400               ret 4

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
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}

template<class T>
class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* get() const { return px; }
};

template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
template<class T, class U> inline bool operator!=(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() != b.get(); }
}

struct Instance;
boost::shared_ptr<Instance> shared_from(Instance* i);

struct CRobloxTreeCtrlNode {
    char pad[0x104];
    std::vector<boost::shared_ptr<Instance> >* children;
    bool hasChild(Instance* instance);
};

bool CRobloxTreeCtrlNode::hasChild(Instance* instance) {
    return std::find(children->begin(), children->end(), shared_from(instance)) != children->end();
}
