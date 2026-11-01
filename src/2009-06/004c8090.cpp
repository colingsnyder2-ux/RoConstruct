// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail {
namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    double align_;
    char data;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}
}
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { this->assign_to_own(f); }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
namespace detail {
struct thread_data_base;
template<class T> class intrusive_ptr { public: T* p; ~intrusive_ptr(); };
typedef intrusive_ptr<thread_data_base> thread_data_ptr;
}
class mutex {
    long active_count; void* event;
public:
    mutex() : active_count(0), event(0) {}
    ~mutex();
};
class thread {
    struct dummy;
    mutable boost::mutex thread_info_mutex;
    detail::thread_data_ptr thread_info;
    void start_thread();
    template<typename F> static detail::thread_data_ptr make_thread_info(F f);
public:
    template<class F> explicit thread(F f, dummy* = 0) : thread_info(make_thread_info(f)) { start_thread(); }
};
template thread::thread(function0<void>, dummy*);
}
