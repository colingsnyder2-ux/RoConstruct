// from server: 100% by Xemicl
// roc 2012-06 007e8310  unit: RBX::P8GuiObject::?$GetSetImpl  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e8310
//
// 007e8310  6aff                 push -1
// 007e8312  68d88aac00           push 0xac8ad8
// 007e8317  64a100000000         mov eax, dword ptr fs:[0]
// 007e831d  50                   push eax
// 007e831e  64892500000000       mov dword ptr fs:[0], esp
// 007e8325  51                   push ecx
// 007e8326  56                   push esi
// 007e8327  8bf1                 mov esi, ecx
// 007e8329  89742404             mov dword ptr [esp + 4], esi
// 007e832d  8d4e08               lea ecx, [esi + 8]
// 007e8330  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007e8338  e8131ff2ff           call 0x70a250
// 007e833d  8b4e04               mov ecx, dword ptr [esi + 4]
// 007e8340  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 007e8348  5e                   pop esi
// 007e8349  85c9                 test ecx, ecx
// 007e834b  7413                 je 0x7e8360
// 007e834d  8d4108               lea eax, [ecx + 8]
// 007e8350  83caff               or edx, 0xffffffff
// 007e8353  f00fc110             lock xadd dword ptr [eax], edx
// 007e8357  7507                 jne 0x7e8360
// 007e8359  8b01                 mov eax, dword ptr [ecx]
// 007e835b  8b5008               mov edx, dword ptr [eax + 8]
// 007e835e  ffd2                 call edx
// 007e8360  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e8364  64890d00000000       mov dword ptr fs:[0], ecx
// 007e836b  83c410               add esp, 0x10
// 007e836e  c3                   ret 
// copied from an identical function in another client (function ??1Holder@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc 2009-06 004d9260
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_;
    long weak_count_;
};
class weak_count {
public:
    sp_counted_base* pi_;
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
}
namespace RBX {
class Instance;
class ExeMap { public: ~ExeMap(); char data[0x1c]; };
class Holder {
public:
    boost::weak_ptr<Instance> owner;
    ExeMap map;
    ~Holder();
};
Holder::~Holder() {}
}