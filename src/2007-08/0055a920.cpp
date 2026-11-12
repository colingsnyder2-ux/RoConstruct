// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 45% by colin
// roc 2007-08 0055a920  unit: RBX::VTool::?$FactoryProduct::Creator  size: 234 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055a920
// 0055a920  64a100000000         mov eax, dword ptr fs:[0]
// 0055a926  6aff                 push -1
// 0055a928  68d8bc7500           push 0x75bcd8
// 0055a92d  50                   push eax
// 0055a92e  64892500000000       mov dword ptr fs:[0], esp
// 0055a935  83ec08               sub esp, 8
// 0055a938  56                   push esi
// 0055a939  8bf1                 mov esi, ecx
// 0055a93b  e850fbffff           call 0x55a490
// 0055a940  85c0                 test eax, eax
// 0055a942  0f85b2000000         jne 0x55a9fa
// 0055a948  53                   push ebx
// 0055a949  8d442408             lea eax, [esp + 8]
// 0055a94d  57                   push edi
// 0055a94e  50                   push eax
// 0055a94f  e8fc34eeff           call 0x43de50
// 0055a954  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055a958  681c1f8c00           push 0x8c1f1c
// 0055a95d  68d0885500           push 0x5588d0
// 0055a962  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0055a96a  e8b1ab1c00           call 0x725520
// 0055a96f  83c40c               add esp, 0xc
// 0055a972  e849cfffff           call 0x5578c0
// 0055a977  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 0055a97d  85c9                 test ecx, ecx
// 0055a97f  8bf8                 mov edi, eax
// 0055a981  740f                 je 0x55a992
// 0055a983  8b8638010000         mov eax, dword ptr [esi + 0x138]
// 0055a989  2bc1                 sub eax, ecx
// 0055a98b  c1f803               sar eax, 3
// 0055a98e  3bf8                 cmp edi, eax
// 0055a990  7206                 jb 0x55a998
// 0055a992  ff15d8e67700         call dword ptr [0x77e6d8]
// 0055a998  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 0055a99e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0055a9a2  8d04f9               lea eax, [ecx + edi*8]
// 0055a9a5  8d4c2410             lea ecx, [esp + 0x10]
// 0055a9a9  51                   push ecx
// 0055a9aa  8d4804               lea ecx, [eax + 4]
// 0055a9ad  8910                 mov dword ptr [eax], edx
// 0055a9af  e8ac80eaff           call 0x402a60
// 0055a9b4  56                   push esi
// 0055a9b5  8bcb                 mov ecx, ebx
// 0055a9b7  e8746cfeff           call 0x541630
// 0055a9bc  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055a9c0  85f6                 test esi, esi
// 0055a9c2  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0055a9ca  742a                 je 0x55a9f6
// 0055a9cc  8d5604               lea edx, [esi + 4]
// 0055a9cf  83c8ff               or eax, 0xffffffff
// 0055a9d2  f00fc102             lock xadd dword ptr [edx], eax
// 0055a9d6  751e                 jne 0x55a9f6
// 0055a9d8  8b16                 mov edx, dword ptr [esi]
// 0055a9da  8b4204               mov eax, dword ptr [edx + 4]
// 0055a9dd  8bce                 mov ecx, esi
// 0055a9df  ffd0                 call eax
// 0055a9e1  8d4e08               lea ecx, [esi + 8]
// 0055a9e4  83caff               or edx, 0xffffffff
// 0055a9e7  f00fc111             lock xadd dword ptr [ecx], edx
// 0055a9eb  7509                 jne 0x55a9f6
// 0055a9ed  8b06                 mov eax, dword ptr [esi]
// 0055a9ef  8b5008               mov edx, dword ptr [eax + 8]
// 0055a9f2  8bce                 mov ecx, esi
// 0055a9f4  ffd2                 call edx
// 0055a9f6  5f                   pop edi
// 0055a9f7  8bc3                 mov eax, ebx
// 0055a9f9  5b                   pop ebx
// 0055a9fa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055a9fe  5e                   pop esi
// 0055a9ff  64890d00000000       mov dword ptr fs:[0], ecx
// 0055aa06  83c414               add esp, 0x14
// 0055aa09  c3                   ret 

#include <vector>
#include <intrin.h>
#pragma intrinsic(_InterlockedDecrement)

namespace boost {

namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;            // +4
    long weak_count_;           // +8
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

class shared_count {
    sp_counted_base* pi_;
public:
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);     // 0x402a60
};
}

template<class T> class shared_ptr {
public:
    T* get() const { return px; }
    T* operator->() const { return px; }
    T* px;
    detail::shared_count pn;
};

struct once_flag { long epoch; };
void call_once(void (*func)(), once_flag& flag);        // 0x725520

}

namespace RBX {

class Instance;

class Tool {
public:
    void setOwner(Instance* owner);                      // 0x541630
};

boost::shared_ptr<Tool> createTool();                    // 0x43de50
void initToolIndex();                                     // 0x5588d0
extern boost::once_flag toolIndexFlag;                    // 0x8c1f1c
unsigned int toolIndex();                                 // 0x5578c0

class Instance {
    int pad[0x130 / 4];
    std::vector< boost::shared_ptr<Tool> > products;      // _Myfirst at +0x134 (VS2005 vector keeps its allocator first)
public:
    Tool* findTool();                                     // 0x55a490
    Tool* create();
};

Tool* Instance::create()
{
    Tool* result = findTool();
    if (result == 0) {
        boost::shared_ptr<Tool> tool = createTool();
        result = tool.get();
        boost::call_once(&initToolIndex, toolIndexFlag);
        products[toolIndex()] = tool;
        result->setOwner(this);
    }
    return result;
}

}
