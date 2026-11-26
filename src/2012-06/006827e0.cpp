// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#define ARG T
#define INST A*, B*
#define ARG1 T1
#define ARG2 T2
#include <vector>
namespace RBX { namespace Reflection {
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
    template<class T> void assign(ARG);
};
class Variant {
public:
    const Type* type;
    Storage value;
    Variant();
    Variant(const Variant&);
    Variant& operator=(const Variant&);
    template<class T> Variant& operator=(ARG v) { type = &Type::singleton<T>(); value.assign<T>(v); return *this; }
};
class A; class B;
class Sink {
public:
    virtual void f0();
    virtual void process(const std::vector<Variant>& args);
    template<class T1, class T2> void fire(ARG1 a1, ARG2 a2);
};
template<class T1, class T2> void Sink::fire(ARG1 a1, ARG2 a2)
{
    std::vector<Variant> args(2);
    args[0].operator=<T1>(a1);
    args[1].operator=<T2>(a2);
    process(args);
}
template void Sink::fire<A*, B*>(INST);
}}
