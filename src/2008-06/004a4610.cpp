// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>


namespace RBX {
    namespace Reflection {
        class DescribedBase { public:
            virtual ~DescribedBase();
        };
    }

    namespace Network {
        class Server : public Reflection::DescribedBase {
        };
    }
}

struct Content {
    virtual ~Content();
    virtual void type() const;
    virtual Content* clone() const;
};

struct Value {
    int value;
    Content* content;

    static Content* copyContent(Content*);
    Value(const Value&);
    ~Value();
    int* get();
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
    void (__thiscall* function)(void*, int, int);
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

    RBX::Network::Server* server =
        dynamic_cast<RBX::Network::Server*>(source);

    if (!server)
        throw std::bad_cast("bad cast");

    int* secondValue = b.get();
    int* firstValue = a.get();

    function(reinterpret_cast<char*>(server) + adjustment,
             *firstValue, *secondValue);
}
