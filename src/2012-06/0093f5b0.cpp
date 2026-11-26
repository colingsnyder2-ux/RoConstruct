// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace mpl { struct false_ {}; }
namespace detail { namespace function {
union function_buffer;
struct function_obj_tag {};
bool has_empty_target(...);
template <class T> inline T* addressof(T& v) { return &v; }
struct BoundArgs
{
    char data[0x18];
    ~BoundArgs();
};
struct BoundFunctor
{
    int f[2];
    BoundArgs l;
    BoundFunctor(const BoundFunctor&);
};
struct basic_vtable1
{
    template <typename FunctionObj>
    void assign_functor(FunctionObj f, function_buffer& functor, mpl::false_);
    template <typename FunctionObj>
    bool assign_to(FunctionObj f, function_buffer& functor, function_obj_tag)
    {
        if (!has_empty_target(addressof(f)))
        {
            assign_functor(f, functor, mpl::false_());
            return true;
        }
        else
        {
            return false;
        }
    }
};
template bool basic_vtable1::assign_to<BoundFunctor>(BoundFunctor, function_buffer&, function_obj_tag);
}}}