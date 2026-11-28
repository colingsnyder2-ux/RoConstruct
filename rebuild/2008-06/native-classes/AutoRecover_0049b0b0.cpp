// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/shared_ptr.hpp>
#include <boost/any.hpp>

// INFERRED: minimal local declarations, since no native headers were shown.
namespace RBX {
    class Instance;
    namespace Reflection {
        class Type;
    }
}

typedef boost::shared_ptr<RBX::Instance> InstancePtr;

// RBX::Reflection::Value::convert<int>()
extern "C" int* __fastcall fn_0056ea60(void* self, int unusedEdx);
// RBX::Reflection::Type::singleton<shared_ptr<Instance>>()
extern "C" const RBX::Reflection::Type* fn_0056cae0();

// INFERRED: a reflection value holding a type pointer and a boost::any.
struct ReflValue {
    const RBX::Reflection::Type* type;
    boost::any value;

    template<class T>
    void set(const T& v)
    {
        type = fn_0056cae0();
        value = v;
    }
};

// INFERRED: a single-inheritance target class, so the member pointer is 4 bytes.
class InvokeTarget {
public:
    InstancePtr callFn(int);
};

typedef InstancePtr (InvokeTarget::*InstanceMethod)(int);

// INFERRED: a bound member-function descriptor, with the member pointer at +0x38 and the object offset at +0x3c.
struct InstanceMethodInvoker {
    char pad[0x38];
    InstanceMethod fn;
    int thisAdjust;
};

extern "C" void __fastcall fn_0049b0b0(InstanceMethodInvoker* self, int unusedEdx,
                                       int object,
                                       ReflValue* result,
                                       void* args)
{
    result->set((((InvokeTarget*)(object + self->thisAdjust))->*(self->fn))(*fn_0056ea60(args, unusedEdx)));
}
