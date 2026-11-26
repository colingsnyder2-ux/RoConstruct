// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Name { public: static const Name& declare(const char* const& s); };
namespace Reflection {
class Type {
public:
    template<class T> static const Type& singleton();
};
struct Storage {
    struct Table { void (*a)(); void (*destroy)(void*); };
    Table* table;
    char data[0x3c];
    Storage();
    Storage(const Storage&);
    ~Storage() { if (table) table->destroy(data); }
};
class Variant {
public:
    const Type* type;
    Storage value;
};
template<class T> struct Arg {
    const char* name;
    Variant defaultValue;
};
struct SignatureDescriptor {
    const Type* resultType;
    void addArgument(const Name& name, const Type& type, const Variant& defaultValue); template<class T> void add(const Arg<T>& a) { const Type& t = Type::singleton<T>(); addArgument(Name::declare(a.name), t, a.defaultValue); }
};
class A; class B; class C;
class Desc {
public:
    char pad[0x1c];
    SignatureDescriptor signature;
    template<class A1, class A2, class A3> void init(Arg<A1> a1, Arg<A2> a2, Arg<A3> a3);
};
template<class A1, class A2, class A3> void Desc::init(Arg<A1> a1, Arg<A2> a2, Arg<A3> a3)
{
    signature.resultType = &Type::singleton<void>();
    signature.add<A1>(a1);
    signature.add<A2>(a2);
    signature.add<A3>(a3);
}
template void Desc::init<A, B, C>(Arg<A>, Arg<B>, Arg<C>);
}}

