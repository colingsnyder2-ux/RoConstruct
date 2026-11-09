// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Reflection {
class Type { public: static const Type& singletonVoid(); };
extern int valueCount;
class Value {
public:
    const Type* type;
    void* content;
    Value();
};
Value::Value()
{
    ++valueCount;
    type = &Type::singletonVoid();
    content = 0;
}
}}
