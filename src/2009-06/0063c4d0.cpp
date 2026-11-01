// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Reflection {
class Type { public: template<class T> static const Type& singleton(); };
template<class T> struct ExeCounter { static int n; };
struct Content { Content(); void* p; };
class Value {
public:
    const Type* type;
    Content content;
    Value();
};
template<class T> inline const Type* counted() { ++ExeCounter<T>::n; return &Type::singleton<T>(); }
Value::Value() : type(counted<void>())
{
}
}}
