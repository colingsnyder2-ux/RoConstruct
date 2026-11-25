// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>

// INFERRED: minimal stand-in for boost::any; only the templated operator= is needed.
namespace boost {
    class any {
    public:
        template<class T> any& operator=(const T& rhs);
        void* content;
    };
}

namespace RBX {
    class Instance;
    namespace Reflection {
        class Type {
        public:
            template<class T> static const Type& singleton();
        };
        struct Value {
            const Type* type;
            boost::any  value;
            template<class T> T& convert();
            // INFERRED: inline setter storing type then value
            template<class T> void set(const T& v)
            {
                type = &Type::singleton<T>();
                value = v;
            }
        };
    }
}

using RBX::Instance;
using RBX::Reflection::Value;
using RBX::Reflection::Type;

// INFERRED: target object type; the bound method takes and returns shared_ptr<Instance> by value.
struct ObjThis {
    boost::shared_ptr<Instance> method(boost::shared_ptr<Instance> a);
};
typedef boost::shared_ptr<Instance> (ObjThis::*InstFn)(boost::shared_ptr<Instance>);

// INFERRED: member-function descriptor with the method pointer at +0x38 and this-adjust at +0x3c
struct MemberFnDesc {
    char       pad[0x38];
    InstFn     fn;
    int        thisAdjust;
};

extern "C" void __fastcall fn_0049b810(MemberFnDesc* self, int unusedEdx, char* obj, Value* result, Value* arg)
{
    result->set(((ObjThis*)(obj + self->thisAdjust)->*(self->fn))(arg->convert< boost::shared_ptr<Instance> >()));
}
