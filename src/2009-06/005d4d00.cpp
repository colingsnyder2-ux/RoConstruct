// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2009-06 005d4d00  unit: RBX::Selection  size: 482 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d4d00
//
// 005d4d00  6aff                 push -1
// 005d4d02  68302d8600           push 0x862d30
// 005d4d07  64a100000000         mov eax, dword ptr fs:[0]
// 005d4d0d  50                   push eax
// 005d4d0e  64892500000000       mov dword ptr fs:[0], esp
// 005d4d15  83ec1c               sub esp, 0x1c
// 005d4d18  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005d4d1c  53                   push ebx
// 005d4d1d  55                   push ebp
// 005d4d1e  56                   push esi
// 005d4d1f  57                   push edi
// 005d4d20  8bf1                 mov esi, ecx
// 005d4d22  50                   push eax
// 005d4d23  8d4c2418             lea ecx, [esp + 0x18]
// 005d4d27  51                   push ecx
// 005d4d28  89742418             mov dword ptr [esp + 0x18], esi
// 005d4d2c  e87f3c0300           call 0x6089b0
// 005d4d31  83c408               add esp, 8
// 005d4d34  8d8e8c000000         lea ecx, [esi + 0x8c]
// 005d4d3a  c744243400000000     mov dword ptr [esp + 0x34], 0
// 005d4d42  e86963efff           call 0x4cb0b0
// 005d4d47  8b30                 mov esi, dword ptr [eax]
// 005d4d49  8b4004               mov eax, dword ptr [eax + 4]
// 005d4d4c  8974241c             mov dword ptr [esp + 0x1c], esi
// 005d4d50  89442420             mov dword ptr [esp + 0x20], eax
// 005d4d54  85c0                 test eax, eax
// 005d4d56  740c                 je 0x5d4d64
// 005d4d58  83c004               add eax, 4
// 005d4d5b  ba01000000           mov edx, 1
// 005d4d60  f00fc110             lock xadd dword ptr [eax], edx
// 005d4d64  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 005d4d67  c644243401           mov byte ptr [esp + 0x34], 1
// 005d4d6c  396e0c               cmp dword ptr [esi + 0xc], ebp
// 005d4d6f  7606                 jbe 0x5d4d77
// 005d4d71  ff15ace98900         call dword ptr [0x89e9ac]
// 005d4d77  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005d4d7a  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005d4d7d  7606                 jbe 0x5d4d85
// 005d4d7f  ff15ace98900         call dword ptr [0x89e9ac]
// 005d4d85  8b1e                 mov ebx, dword ptr [esi]
// 005d4d87  897c2428             mov dword ptr [esp + 0x28], edi
// 005d4d8b  3bfd                 cmp edi, ebp
// 005d4d8d  740f                 je 0x5d4d9e
// 005d4d8f  8b442414             mov eax, dword ptr [esp + 0x14]
// 005d4d93  3907                 cmp dword ptr [edi], eax
// 005d4d95  7407                 je 0x5d4d9e
// 005d4d97  83c708               add edi, 8
// 005d4d9a  3bfd                 cmp edi, ebp
// 005d4d9c  75f5                 jne 0x5d4d93
// 005d4d9e  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 005d4da1  396e0c               cmp dword ptr [esi + 0xc], ebp
// 005d4da4  7606                 jbe 0x5d4dac
// 005d4da6  ff15ace98900         call dword ptr [0x89e9ac]
// 005d4dac  8b06                 mov eax, dword ptr [esi]
// 005d4dae  85db                 test ebx, ebx
// 005d4db0  7404                 je 0x5d4db6
// 005d4db2  3bd8                 cmp ebx, eax
// 005d4db4  7406                 je 0x5d4dbc
// 005d4db6  ff15ace98900         call dword ptr [0x89e9ac]
// 005d4dbc  8bce                 mov ecx, esi
// 005d4dbe  3bfd                 cmp edi, ebp
// 005d4dc0  754d                 jne 0x5d4e0f
// 005d4dc2  8d442414             lea eax, [esp + 0x14]
// 005d4dc6  50                   push eax
// 005d4dc7  e8f4a21300           call 0x70f0c0
// 005d4dcc  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005d4dd0  8b742410             mov esi, dword ptr [esp + 0x10]
// 005d4dd4  51                   push ecx
// 005d4dd5  8bce                 mov ecx, esi
// 005d4dd7  e894feffff           call 0x5d4c70
// 005d4ddc  8b542414             mov edx, dword ptr [esp + 0x14]
// 005d4de0  83ec08               sub esp, 8
// 005d4de3  8bc4                 mov eax, esp
// 005d4de5  8910                 mov dword ptr [eax], edx
// 005d4de7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005d4deb  894804               mov dword ptr [eax + 4], ecx
// 005d4dee  8b442420             mov eax, dword ptr [esp + 0x20]
// 005d4df2  89642444             mov dword ptr [esp + 0x44], esp
// 005d4df6  85c0                 test eax, eax
// 005d4df8  740c                 je 0x5d4e06
// 005d4dfa  83c004               add eax, 4
// 005d4dfd  ba01000000           mov edx, 1
// 005d4e02  f00fc110             lock xadd dword ptr [eax], edx
// 005d4e06  8bce                 mov ecx, esi
// 005d4e08  e843f1ffff           call 0x5d3f50
// 005d4e0d  eb4d                 jmp 0x5d4e5c
// 005d4e0f  57                   push edi
// 005d4e10  53                   push ebx
// 005d4e11  8d44242c             lea eax, [esp + 0x2c]
// 005d4e15  50                   push eax
// 005d4e16  e895960c00           call 0x69e4b0
// 005d4e1b  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005d4e1f  8b742410             mov esi, dword ptr [esp + 0x10]
// 005d4e23  51                   push ecx
// 005d4e24  8bce                 mov ecx, esi
// 005d4e26  e8d5eaffff           call 0x5d3900
// 005d4e2b  8b542414             mov edx, dword ptr [esp + 0x14]
// 005d4e2f  83ec08               sub esp, 8
// 005d4e32  8bc4                 mov eax, esp
// 005d4e34  8910                 mov dword ptr [eax], edx
// 005d4e36  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005d4e3a  894804               mov dword ptr [eax + 4], ecx
// 005d4e3d  8b442420             mov eax, dword ptr [esp + 0x20]
// 005d4e41  89642444             mov dword ptr [esp + 0x44], esp
// 005d4e45  85c0                 test eax, eax
// 005d4e47  740c                 je 0x5d4e55
// 005d4e49  83c004               add eax, 4
// 005d4e4c  ba01000000           mov edx, 1
// 005d4e51  f00fc110             lock xadd dword ptr [eax], edx
// 005d4e55  8bce                 mov ecx, esi
// 005d4e57  e864f2ffff           call 0x5d40c0
// 005d4e5c  8b742420             mov esi, dword ptr [esp + 0x20]
// 005d4e60  c644243400           mov byte ptr [esp + 0x34], 0
// 005d4e65  85f6                 test esi, esi
// 005d4e67  742a                 je 0x5d4e93
// 005d4e69  8d4604               lea eax, [esi + 4]
// 005d4e6c  83c9ff               or ecx, 0xffffffff
// 005d4e6f  f00fc108             lock xadd dword ptr [eax], ecx
// 005d4e73  751e                 jne 0x5d4e93
// 005d4e75  8b16                 mov edx, dword ptr [esi]
// 005d4e77  8b4204               mov eax, dword ptr [edx + 4]
// 005d4e7a  8bce                 mov ecx, esi
// 005d4e7c  ffd0                 call eax
// 005d4e7e  8d4e08               lea ecx, [esi + 8]
// 005d4e81  83caff               or edx, 0xffffffff
// 005d4e84  f00fc111             lock xadd dword ptr [ecx], edx
// 005d4e88  7509                 jne 0x5d4e93
// 005d4e8a  8b06                 mov eax, dword ptr [esi]
// 005d4e8c  8b5008               mov edx, dword ptr [eax + 8]
// 005d4e8f  8bce                 mov ecx, esi
// 005d4e91  ffd2                 call edx
// 005d4e93  8b742418             mov esi, dword ptr [esp + 0x18]
// 005d4e97  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 005d4e9f  85f6                 test esi, esi
// 005d4ea1  742a                 je 0x5d4ecd
// 005d4ea3  8d4604               lea eax, [esi + 4]
// 005d4ea6  83c9ff               or ecx, 0xffffffff
// 005d4ea9  f00fc108             lock xadd dword ptr [eax], ecx
// 005d4ead  751e                 jne 0x5d4ecd
// 005d4eaf  8b16                 mov edx, dword ptr [esi]
// 005d4eb1  8b4204               mov eax, dword ptr [edx + 4]
// 005d4eb4  8bce                 mov ecx, esi
// 005d4eb6  ffd0                 call eax
// 005d4eb8  8d4e08               lea ecx, [esi + 8]
// 005d4ebb  83caff               or edx, 0xffffffff
// 005d4ebe  f00fc111             lock xadd dword ptr [ecx], edx
// 005d4ec2  7509                 jne 0x5d4ecd
// 005d4ec4  8b06                 mov eax, dword ptr [esi]
// 005d4ec6  8b5008               mov edx, dword ptr [eax + 8]
// 005d4ec9  8bce                 mov ecx, esi
// 005d4ecb  ffd2                 call edx
// 005d4ecd  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d4ed1  5f                   pop edi
// 005d4ed2  5e                   pop esi
// 005d4ed3  5d                   pop ebp
// 005d4ed4  64890d00000000       mov dword ptr fs:[0], ecx
// 005d4edb  5b                   pop ebx
// 005d4edc  83c428               add esp, 0x28
// 005d4edf  c20400               ret 4

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <algorithm>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r)
    {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) {
            if (tmp != 0) tmp->add_ref_copy();
            if (pi_ != 0) pi_->release();
            pi_ = tmp;
        }
        return *this;
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    T* get() const { return px; }
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
}

namespace RBX {
class Instance;
struct AncestorChanged;
template<class Class, class Event> class Listener {
public:
    virtual void onEvent(const Class*, Event) = 0;
};
template<class Class, class Event> class Notifier {
public:
    void addListener(Listener<Class, Event>* listener) const;
    void removeListener(Listener<Class, Event>* listener) const;
};
template<class Class> boost::shared_ptr<Class> shared_from(Class*);
template<class T> class CopyOnWrite {
public:
    const boost::shared_ptr<T>& write();
};
struct AncestorChanged {};

struct SelectionPrefix {
    virtual ~SelectionPrefix();
    char pad[0x88];
};

class Selection : public SelectionPrefix {
public:
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > selection;
    void connectInstance(Instance*);
    void disconnectInstance(Instance*);
    void raiseAdded(boost::shared_ptr<Instance> instance);
    void raiseRemoved(boost::shared_ptr<Instance> instance);
    void toggleSelection(Instance* instance);
};

void Selection::toggleSelection(Instance* instance)
{
    boost::shared_ptr<Instance> shared = shared_from(instance);
    boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > sel = selection.write();

    std::vector<boost::shared_ptr<Instance> >::iterator found = std::find(sel->begin(), sel->end(), shared);

    if (found == sel->end())
    {
        sel->push_back(shared);
        connectInstance(instance);
        raiseAdded(shared);
    }
    else
    {
        sel->erase(found);
        disconnectInstance(instance);
        raiseRemoved(shared);
    }
}
}
