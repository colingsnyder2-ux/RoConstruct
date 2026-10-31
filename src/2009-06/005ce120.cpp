// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance;
namespace Reflection {
class Type { public: Type(const char* name, const char* tag, int x); virtual ~Type(); };
class RefType : public Type {
public:
    RefType(const char* name) : Type(name, "Ref", 0) {}
    virtual ~RefType() {}
    template<class T> static const RefType& singleton()
    {
        static RefType type("Object");
        return type;
    }
};
template const RefType& RefType::singleton<Instance*>();
}}
