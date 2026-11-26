// from server: 100% by Xemicl
// roc 2012-06 00521110  unit: rbx::signals::$$A6AXXZ::?$signal::Vslot::?$callable  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00521110
//
// 00521110  56                   push esi
// 00521111  57                   push edi
// 00521112  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00521116  8bf1                 mov esi, ecx
// 00521118  c70600000000         mov dword ptr [esi], 0
// 0052111e  8b07                 mov eax, dword ptr [edi]
// 00521120  85c0                 test eax, eax
// 00521122  7415                 je 0x521139
// 00521124  8906                 mov dword ptr [esi], eax
// 00521126  8b07                 mov eax, dword ptr [edi]
// 00521128  8b00                 mov eax, dword ptr [eax]
// 0052112a  6a00                 push 0
// 0052112c  8d4e08               lea ecx, [esi + 8]
// 0052112f  51                   push ecx
// 00521130  8d5708               lea edx, [edi + 8]
// 00521133  52                   push edx
// 00521134  ffd0                 call eax
// 00521136  83c40c               add esp, 0xc
// 00521139  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 0052113c  894e20               mov dword ptr [esi + 0x20], ecx
// 0052113f  8b5724               mov edx, dword ptr [edi + 0x24]
// 00521142  895624               mov dword ptr [esi + 0x24], edx
// 00521145  8b4728               mov eax, dword ptr [edi + 0x28]
// 00521148  894628               mov dword ptr [esi + 0x28], eax
// 0052114b  8b4f2c               mov ecx, dword ptr [edi + 0x2c]
// 0052114e  894e2c               mov dword ptr [esi + 0x2c], ecx
// 00521151  8b5730               mov edx, dword ptr [edi + 0x30]
// 00521154  895630               mov dword ptr [esi + 0x30], edx
// 00521157  8b4734               mov eax, dword ptr [edi + 0x34]
// 0052115a  894634               mov dword ptr [esi + 0x34], eax
// 0052115d  8b4f38               mov ecx, dword ptr [edi + 0x38]
// 00521160  894e38               mov dword ptr [esi + 0x38], ecx
// 00521163  8b573c               mov edx, dword ptr [edi + 0x3c]
// 00521166  5f                   pop edi
// 00521167  89563c               mov dword ptr [esi + 0x3c], edx
// 0052116a  c6464000             mov byte ptr [esi + 0x40], 0
// 0052116e  8bc6                 mov eax, esi
// 00521170  5e                   pop esi
// 00521171  c20400               ret 4
// copied from an identical function in another client (function ??0?$split_iterator@V?$_String_iterator@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@algorithm@boost@@QAE@ABV012@@Z)

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