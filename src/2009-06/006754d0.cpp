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
