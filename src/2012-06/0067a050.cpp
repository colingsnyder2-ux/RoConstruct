// from server: 100% by Xemicl
// roc 2012-06 0067a050  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067a050
//
// 0067a050  6aff                 push -1
// 0067a052  6808c8ac00           push 0xacc808
// 0067a057  64a100000000         mov eax, dword ptr fs:[0]
// 0067a05d  50                   push eax
// 0067a05e  64892500000000       mov dword ptr fs:[0], esp
// 0067a065  83ec0c               sub esp, 0xc
// 0067a068  8d442404             lea eax, [esp + 4]
// 0067a06c  56                   push esi
// 0067a06d  50                   push eax
// 0067a06e  e86d1edcff           call 0x43bee0
// 0067a073  8b00                 mov eax, dword ptr [eax]
// 0067a075  8b5034               mov edx, dword ptr [eax + 0x34]
// 0067a078  8d4c2408             lea ecx, [esp + 8]
// 0067a07c  51                   push ecx
// 0067a07d  52                   push edx
// 0067a07e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0067a086  e815a62f00           call 0x9746a0
// 0067a08b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0067a08f  83c40c               add esp, 0xc
// 0067a092  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0067a09a  85f6                 test esi, esi
// 0067a09c  742a                 je 0x67a0c8
// 0067a09e  8d4604               lea eax, [esi + 4]
// 0067a0a1  83c9ff               or ecx, 0xffffffff
// 0067a0a4  f00fc108             lock xadd dword ptr [eax], ecx
// 0067a0a8  751e                 jne 0x67a0c8
// 0067a0aa  8b16                 mov edx, dword ptr [esi]
// 0067a0ac  8b4204               mov eax, dword ptr [edx + 4]
// 0067a0af  8bce                 mov ecx, esi
// 0067a0b1  ffd0                 call eax
// 0067a0b3  8d4e08               lea ecx, [esi + 8]
// 0067a0b6  83caff               or edx, 0xffffffff
// 0067a0b9  f00fc111             lock xadd dword ptr [ecx], edx
// 0067a0bd  7509                 jne 0x67a0c8
// 0067a0bf  8b06                 mov eax, dword ptr [esi]
// 0067a0c1  8b5008               mov edx, dword ptr [eax + 8]
// 0067a0c4  8bce                 mov ecx, esi
// 0067a0c6  ffd2                 call edx
// 0067a0c8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067a0cc  8b442404             mov eax, dword ptr [esp + 4]
// 0067a0d0  5e                   pop esi
// 0067a0d1  64890d00000000       mov dword ptr fs:[0], ecx
// 0067a0d8  83c418               add esp, 0x18
// 0067a0db  c3                   ret 
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
    getCounterValue(getPerfCounters()->processorTime, value);
    return value;
}
}