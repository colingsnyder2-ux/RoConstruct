// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    double align;
    char data;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor) { if (manager) manager(functor, functor, destroy_functor_tag); }
};
}}
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class Sig> class function : public function_base {
public:
    function(const function& f) : function_base() { assign_to_own(f); }
    ~function() { clear(); }
    void assign_to_own(const function& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
    void clear() { if (vtable) { vtable->clear(this->functor); } }
};
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
template<class T> struct Countable {
    static long volatile count;
    Countable() { InterlockedIncrement(&count); }
};
extern int defaultValue;
class Job : public Countable<Job> {
public:
    Job() : i8(0), ic(defaultValue) {}
    virtual ~Job();
    struct Flags { bool b4; bool b5; Flags() : b5(true) {} } flags;
    int i8;
    int ic;
};
typedef boost::function<void()> Callback;
class FunctionJob : public Job {
public:
    int arg;
    int pad14;
    Callback func;
    int a, b, c, d;
    FunctionJob(Callback f, int x);
    virtual ~FunctionJob();
};
FunctionJob::FunctionJob(Callback f, int x) : arg(x), func(f), a(0), b(0), c(0), d(0) {}
