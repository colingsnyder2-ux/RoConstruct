// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <list>
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer&, function_buffer&, functor_manager_operation_type);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
};
template<class Sig> class function;
template<> class function<void()> : public function_base {
public:
    function() {}
    function(const function&);
    ~function() { clear(); }
    function& operator=(const function&);
    void clear() {
        if (vtable) {
            void (*m)(const detail::function::function_buffer&, detail::function::function_buffer&, detail::function::functor_manager_operation_type) = vtable->manager;
            if (m)
                m(functor, functor, detail::function::destroy_functor_tag);
            vtable = 0;
        }
    }
};
}
struct Time { double t; Time(const Time& o) : t(o.t) {} Time(double x) : t(x) {} Time operator+(double d) const { return Time(t + d); } };
extern Time __cdecl timer_now();
struct Value {double time; boost::function<void()> callback; Value() : time(0) {}};
struct Service {char padding[0x9c];std::list<Value> timers;void schedule(boost::function<void()> callback,double delay);};
void Service::schedule(boost::function<void()> callback,double delay) {
 Value value;value.time=(timer_now()+delay).t;value.callback=callback;
 for(std::list<Value>::iterator i=timers.begin();i!=timers.end();++i) {
  if(i->time>value.time) {timers.insert(i,value);goto finished;}
 }
 timers.push_back(value);
finished:;
}
