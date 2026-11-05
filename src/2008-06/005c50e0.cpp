// from server: 100% by Espeon
// from server: 88% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>


namespace RBX {
    namespace Reflection {
        class DescribedBase { public:
            virtual ~DescribedBase();
        };
    }
}

namespace RBX { class Visit : public Reflection::DescribedBase {
}; }

struct Content {
    virtual ~Content();
    virtual void type() const;
    virtual Content* clone() const;
};

struct String { char bytes[28]; __declspec(dllimport) String(const String&); __declspec(dllimport) ~String(); };

struct Value {
    int value;
    Content* content;

    static Content* copyContent(Content*);
    Value(const Value&);
    ~Value();
    int* get();
    String* getString();
};

inline Content* Value::copyContent(Content* source)
{
    if (source)
        return source->clone();
    return 0;
}

inline Value::Value(const Value& other)
    : value(other.value), content(copyContent(other.content))
{
}

inline Value::~Value()
{
    if (content)
        delete content;
}

struct Arguments {
    virtual void unused();
    virtual void assign(int, Value*);
};

struct BoundFuncDesc {
    char padding[56];
    void (__thiscall* function)(void*, String, int);
    int adjustment;
    Value first;
    Value second;

    void invoke(RBX::Reflection::DescribedBase*, Arguments*);
};

void BoundFuncDesc::invoke(RBX::Reflection::DescribedBase* source,
                           Arguments* arguments)
{
    Value a(first);
    arguments->assign(1, &a);

    Value b(second);
    arguments->assign(2, &b);

    RBX::Visit* server =
        dynamic_cast<RBX::Visit*>(source);

    if (!server)
        throw std::bad_cast("bad cast");

    function(reinterpret_cast<char*>(server) + adjustment,
             *a.getString(), *b.get());
}
