// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
template<class T> struct type {};
template<class A1, class A2, class A3> struct rrlist3 {
    A1& a1_; A2& a2_; A3& a3_;
    rrlist3(A1& a1, A2& a2, A3& a3) : a1_(a1), a2_(a2), a3_(a3) {}
};
struct F8 { int x, y; };
struct List {
    template<class A> void operator()(type<void>, F8& f, A& a, int);
};
struct Bound {
    F8 f_; List l_;
    template<class A1, class A2, class A3> void operator()(A1& a1, A2& a2, A3& a3) {
        rrlist3<A1, A2, A3> a(a1, a2, a3);
        l_(type<void>(), f_, a, 0);
    }
};
union function_buffer { void* obj_ptr; char data[0x10]; };
struct void_function_obj_invoker3 {
    static void invoke(function_buffer& function_obj_ptr, std::string a0, int a1, std::string a2);
};
void void_function_obj_invoker3::invoke(function_buffer& function_obj_ptr, std::string a0, int a1, std::string a2)
{
    Bound* f = reinterpret_cast<Bound*>(&function_obj_ptr.data);
    (*f)(a0, a1, a2);
}
