// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
namespace detail { namespace function {
class X;
union function_buffer {
    void* obj_ptr;
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    double align_;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class It>
class finder_function : public function_base {
public:
    finder_function(const finder_function& f) { vtable = 0; assign_to_own(f); }
    void assign_to_own(const finder_function& f) {
        if (f.vtable) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
template<class It> struct iterator_range { It m_Begin; It m_End; };
namespace algorithm {
namespace detail {
template<class It>
class find_iterator_base {
protected:
    find_iterator_base(const find_iterator_base& Other) : m_Finder(Other.m_Finder) {}
    finder_function<It> m_Finder;
};
}
template<class It>
class split_iterator : public detail::find_iterator_base<It> {
public:
    split_iterator(const split_iterator& Other)
        : detail::find_iterator_base<It>(Other), m_Match(Other.m_Match), m_Next(Other.m_Next), m_End(Other.m_End), m_bEof(false) {}
    iterator_range<It> m_Match;
    It m_Next;
    It m_End;
    bool m_bEof;
};
template class split_iterator<std::string::iterator>;
}
}
