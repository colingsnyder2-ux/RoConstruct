// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>
namespace G3D { class CoordinateFrame {}; }
namespace boost { template<class E> __declspec(noreturn) void throw_exception(const E& e); }
namespace rbx {
class bad_placement_any_cast : public std::bad_cast {
public:
    virtual const char* what() const throw();
};
struct fxn_ptr_table { const std::type_info* type; };
class placement_any {
public:
    const std::type_info& type() const { return table ? *table->type : typeid(void); }
    fxn_ptr_table* table;
    char storage[16];
};
template<class T> T& placement_any_cast(placement_any& operand)
{
    if (&operand.type() != &typeid(T) && operand.type() != typeid(T))
        boost::throw_exception(bad_placement_any_cast());
    return *reinterpret_cast<T*>(operand.storage);
}
template ::G3D::CoordinateFrame& placement_any_cast<::G3D::CoordinateFrame>(placement_any&);
}
