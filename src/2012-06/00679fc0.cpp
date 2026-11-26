// from server: 100% by Xemicl
// roc 2012-06 00679fc0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00679fc0
//
// 00679fc0  6aff                 push -1
// 00679fc2  6808c8ac00           push 0xacc808
// 00679fc7  64a100000000         mov eax, dword ptr fs:[0]
// 00679fcd  50                   push eax
// 00679fce  64892500000000       mov dword ptr fs:[0], esp
// 00679fd5  83ec0c               sub esp, 0xc
// 00679fd8  8d442404             lea eax, [esp + 4]
// 00679fdc  56                   push esi
// 00679fdd  50                   push eax
// 00679fde  e8fd1edcff           call 0x43bee0
// 00679fe3  8b00                 mov eax, dword ptr [eax]
// 00679fe5  8b5030               mov edx, dword ptr [eax + 0x30]
// 00679fe8  8d4c2408             lea ecx, [esp + 8]
// 00679fec  51                   push ecx
// 00679fed  52                   push edx
// 00679fee  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00679ff6  e8a5a62f00           call 0x9746a0
// 00679ffb  8b742418             mov esi, dword ptr [esp + 0x18]
// 00679fff  83c40c               add esp, 0xc
// 0067a002  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0067a00a  85f6                 test esi, esi
// 0067a00c  742a                 je 0x67a038
// 0067a00e  8d4604               lea eax, [esi + 4]
// 0067a011  83c9ff               or ecx, 0xffffffff
// 0067a014  f00fc108             lock xadd dword ptr [eax], ecx
// 0067a018  751e                 jne 0x67a038
// 0067a01a  8b16                 mov edx, dword ptr [esi]
// 0067a01c  8b4204               mov eax, dword ptr [edx + 4]
// 0067a01f  8bce                 mov ecx, esi
// 0067a021  ffd0                 call eax
// 0067a023  8d4e08               lea ecx, [esi + 8]
// 0067a026  83caff               or edx, 0xffffffff
// 0067a029  f00fc111             lock xadd dword ptr [ecx], edx
// 0067a02d  7509                 jne 0x67a038
// 0067a02f  8b06                 mov eax, dword ptr [esi]
// 0067a031  8b5008               mov edx, dword ptr [eax + 8]
// 0067a034  8bce                 mov ecx, esi
// 0067a036  ffd2                 call edx
// 0067a038  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067a03c  8b442404             mov eax, dword ptr [esp + 4]
// 0067a040  5e                   pop esi
// 0067a041  64890d00000000       mov dword ptr fs:[0], ecx
// 0067a048  83c418               add esp, 0x18
// 0067a04b  c3                   ret 
// copied from an identical function in another client (function ?getTotalProcessorTime@Stats@RBX@@QBEJXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
inline long atomic_decrement(long* pw) { return _InterlockedDecrement(pw); }
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void weak_release() { if (atomic_decrement(&weak_count_) == 0) destroy(); }
    void release() { if (atomic_decrement(&use_count_) == 0) { dispose(); weak_release(); } }
    long use_count_;
    long weak_count_;
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* operator->() const { return px; }
    T* px;
    detail::shared_count pn;
};
}
typedef void* PDH_HCOUNTER;
namespace RBX {
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class PerfCountersImpl {
public:
    char pad[0x30];
    PDH_HCOUNTER totalProcessorTime;
    PDH_HCOUNTER processorTime;
    char pad2[0x40 - 0x38];
    PDH_HCOUNTER pageFileBytes;
    PDH_HCOUNTER virtualBytes;
    PDH_HCOUNTER privateWorkingSetBytes;
};
boost::shared_ptr<PerfCountersImpl> getPerfCounters();
void getCounterValue(PDH_HCOUNTER counter, long& value);
class Stats : public ExeBaseA, public ExeBaseB {
public:
    long getTotalProcessorTime() const;
};
long Stats::getTotalProcessorTime() const
{
    long value;
    getCounterValue(getPerfCounters()->totalProcessorTime, value);
    return value;
}
}