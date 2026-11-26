// from server: 100% by Xemicl
namespace std { template<class T0,class T1,class T2> class basic_string; }
namespace std { template<class T0> struct char_traits; }
namespace std { template<class T0> class allocator; }
// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>

namespace RBX { namespace Reflection { struct Tuple; } }
namespace boost { template<class T> class shared_ptr { T* px; void* pn; }; }

// [this]->+0x10 holds the described value's type_info.
struct Descriptor {
    char pad[0x10]; const std::type_info* type;
    template<class T> bool isType() const {
        if (type == &typeid(T)) return true;
        return typeid(T) == *type;
    }
};
struct DescriptorRef {
    const Descriptor* desc;
    bool isTuple() const;
};

bool DescriptorRef::isTuple() const
{
    return desc->isType<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >();
}
