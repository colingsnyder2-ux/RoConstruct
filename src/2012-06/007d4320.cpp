// from server: 100% by Xemicl
// roc 2012-06 007d4320  unit: RBX::VTimerService::?$FactoryProduct  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007d4320
//
// 007d4320  6aff                 push -1
// 007d4322  6851f6aa00           push 0xaaf651
// 007d4327  64a100000000         mov eax, dword ptr fs:[0]
// 007d432d  50                   push eax
// 007d432e  64892500000000       mov dword ptr fs:[0], esp
// 007d4335  51                   push ecx
// 007d4336  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d433a  89442414             mov dword ptr [esp + 0x14], eax
// 007d433e  890424               mov dword ptr [esp], eax
// 007d4341  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d4349  85c0                 test eax, eax
// 007d434b  7433                 je 0x7d4380
// 007d434d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007d4351  8b11                 mov edx, dword ptr [ecx]
// 007d4353  8910                 mov dword ptr [eax], edx
// 007d4355  8b5104               mov edx, dword ptr [ecx + 4]
// 007d4358  895004               mov dword ptr [eax + 4], edx
// 007d435b  c7400800000000       mov dword ptr [eax + 8], 0
// 007d4362  8b5108               mov edx, dword ptr [ecx + 8]
// 007d4365  85d2                 test edx, edx
// 007d4367  7417                 je 0x7d4380
// 007d4369  895008               mov dword ptr [eax + 8], edx
// 007d436c  8b5108               mov edx, dword ptr [ecx + 8]
// 007d436f  83c010               add eax, 0x10
// 007d4372  6a00                 push 0
// 007d4374  50                   push eax
// 007d4375  8b02                 mov eax, dword ptr [edx]
// 007d4377  83c110               add ecx, 0x10
// 007d437a  51                   push ecx
// 007d437b  ffd0                 call eax
// 007d437d  83c40c               add esp, 0xc
// 007d4380  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d4384  64890d00000000       mov dword ptr fs:[0], ecx
// 007d438b  83c410               add esp, 0x10
// 007d438e  c3                   ret 
// copied from an identical function in another client (function ??$_Construct@VItem@TimerService@RBX@@V123@@std@@YAXPAVItem@TimerService@RBX@@ABV123@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <xmemory>
namespace boost { namespace detail { namespace function {
union __declspec(align(8)) function_buffer { void* obj_ptr; char data[8]; };
struct vtable_base { void (*manager)(const function_buffer& in, function_buffer& out, int op); };
}}
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
};
template<class R> class function0 : public function_base {
public:
    function0() {}
    function0(const function0& f) : function_base() { assign_to_own(f); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, 0);
        }
    }
};
}
namespace RBX {
class TimerService {
public:
    class Item {
    public:
        __int64 time;
        boost::function0<void> func;
    };
};
}
template void std::_Construct<RBX::TimerService::Item, RBX::TimerService::Item>(RBX::TimerService::Item*, const RBX::TimerService::Item&);