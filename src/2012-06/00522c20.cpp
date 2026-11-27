// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct function_buffer;
struct false_ {};
struct function_obj_tag {};
struct Inner
{
    int w[11];
    Inner(const Inner &);
    ~Inner();
};
struct Bound
{
    int a;
    Inner inner;
    Bound(const Bound &);
};
bool has_empty_target(...);
struct basic_vtable0
{
    void assign_functor(Bound f, function_buffer &functor, false_);
    bool assign_to(Bound f, function_buffer &functor, function_obj_tag);
};
bool basic_vtable0::assign_to(Bound f, function_buffer &functor, function_obj_tag)
{
    if (!has_empty_target(&f)) {
        assign_functor(f, functor, false_());
        return true;
    } else {
        return false;
    }
}