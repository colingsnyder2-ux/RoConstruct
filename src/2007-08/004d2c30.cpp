// from server: 86% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 46% by colin
// roc 2007-08 004d2c30  unit: G3D::VVector3::?$Table  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d2c30
//
// 004d2c30  64a100000000         mov eax, dword ptr fs:[0]
// 004d2c36  6aff                 push -1
// 004d2c38  68d8bc7500           push 0x75bcd8
// 004d2c3d  50                   push eax
// 004d2c3e  64892500000000       mov dword ptr fs:[0], esp
// 004d2c45  83ec0c               sub esp, 0xc
// 004d2c48  53                   push ebx
// 004d2c49  55                   push ebp
// 004d2c4a  81c1c0000000         add ecx, 0xc0
// 004d2c50  833900               cmp dword ptr [ecx], 0
// 004d2c53  56                   push esi
// 004d2c54  57                   push edi
// 004d2c55  0f84bc000000         je 0x4d2d17
// 004d2c5b  8d442414             lea eax, [esp + 0x14]
// 004d2c5f  50                   push eax
// 004d2c60  e88b4cf4ff           call 0x4178f0
// 004d2c65  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004d2c69  8b5f08               mov ebx, dword ptr [edi + 8]
// 004d2c6c  395f04               cmp dword ptr [edi + 4], ebx
// 004d2c6f  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004d2c77  7606                 jbe 0x4d2c7f
// 004d2c79  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d2c7f  8b7704               mov esi, dword ptr [edi + 4]
// 004d2c82  3b7708               cmp esi, dword ptr [edi + 8]
// 004d2c85  7606                 jbe 0x4d2c8d
// 004d2c87  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d2c8d  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 004d2c91  3bf3                 cmp esi, ebx
// 004d2c93  7448                 je 0x4d2cdd
// 004d2c95  3b7708               cmp esi, dword ptr [edi + 8]
// 004d2c98  7206                 jb 0x4d2ca0
// 004d2c9a  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d2ca0  8b16                 mov edx, dword ptr [esi]
// 004d2ca2  83ec08               sub esp, 8
// 004d2ca5  8bcc                 mov ecx, esp
// 004d2ca7  8911                 mov dword ptr [ecx], edx
// 004d2ca9  8b4604               mov eax, dword ptr [esi + 4]
// 004d2cac  85c0                 test eax, eax
// 004d2cae  89642418             mov dword ptr [esp + 0x18], esp
// 004d2cb2  894104               mov dword ptr [ecx + 4], eax
// 004d2cb5  740c                 je 0x4d2cc3
// 004d2cb7  83c004               add eax, 4
// 004d2cba  b901000000           mov ecx, 1
// 004d2cbf  f00fc108             lock xadd dword ptr [eax], ecx
// 004d2cc3  55                   push ebp
// 004d2cc4  8d4c2438             lea ecx, [esp + 0x38]
// 004d2cc8  e883dcffff           call 0x4d0950
// 004d2ccd  3b7708               cmp esi, dword ptr [edi + 8]
// 004d2cd0  7206                 jb 0x4d2cd8
// 004d2cd2  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d2cd8  83c608               add esi, 8
// 004d2cdb  ebb4                 jmp 0x4d2c91
// 004d2cdd  8b742418             mov esi, dword ptr [esp + 0x18]
// 004d2ce1  85f6                 test esi, esi
// 004d2ce3  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004d2ceb  742a                 je 0x4d2d17
// 004d2ced  8d5604               lea edx, [esi + 4]
// 004d2cf0  83c8ff               or eax, 0xffffffff
// 004d2cf3  f00fc102             lock xadd dword ptr [edx], eax
// 004d2cf7  751e                 jne 0x4d2d17
// 004d2cf9  8b16                 mov edx, dword ptr [esi]
// 004d2cfb  8b4204               mov eax, dword ptr [edx + 4]
// 004d2cfe  8bce                 mov ecx, esi
// 004d2d00  ffd0                 call eax
// 004d2d02  8d4e08               lea ecx, [esi + 8]
// 004d2d05  83caff               or edx, 0xffffffff
// 004d2d08  f00fc111             lock xadd dword ptr [ecx], edx
// 004d2d0c  7509                 jne 0x4d2d17
// 004d2d0e  8b06                 mov eax, dword ptr [esi]
// 004d2d10  8b5008               mov edx, dword ptr [eax + 8]
// 004d2d13  8bce                 mov ecx, esi
// 004d2d15  ffd2                 call edx
// 004d2d17  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004d2d1b  5f                   pop edi
// 004d2d1c  5e                   pop esi
// 004d2d1d  5d                   pop ebp
// 004d2d1e  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2d25  5b                   pop ebx
// 004d2d26  83c418               add esp, 0x18
// 004d2d29  c20c00               ret 0xc

#include <vector>
#include <algorithm>
#include <intrin.h>

namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;   // vtable +4
    virtual void destroy();       // vtable +8
    long use_count_;              // +4
    long weak_count_;             // +8
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
}

template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pi_;
    shared_ptr(const shared_ptr& r) : px(r.px), pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_ptr() { if (pi_ != 0) pi_->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

namespace RBX {
class Instance;
typedef std::vector<shared_ptr<Instance> > Instances;

class ChildrenPtr {
    shared_ptr<const Instances> p;
public:
    bool notNull() const { return p ? true : false; }
    shared_ptr<const Instances> read() const;   // 0x4178f0 (copy out)
};

namespace View {
class PartChunk { public: void addChild(shared_ptr<Instance>); };
}

// member-function caller (0x4d0950), 4 bytes
struct mf1 {
    void (View::PartChunk::*f_)(shared_ptr<Instance>);
    void operator()(View::PartChunk* p, shared_ptr<Instance> a1) const;
};
struct arg1 {};
// bound functor: mf1 + bound PartChunk* + placeholder (12 bytes)
struct Binder {
    mf1 f_;
    View::PartChunk* p_;
    arg1 a_;
    void operator()(const shared_ptr<Instance>& a) { f_(p_, a); }
};

class InstanceHolder {
public:
    char pad[0xc0];
    ChildrenPtr children;   // +0xc0
    template<class F> void visitChildren(F f) const
    {
        if (children.notNull()) {
            shared_ptr<const Instances> c = children.read();
            const Instances& v = *c.get();
            for (Instances::const_iterator it = v.begin(); it != v.end(); ++it)
                f(*it);
        }
    }
};

template void InstanceHolder::visitChildren(Binder) const;
}
