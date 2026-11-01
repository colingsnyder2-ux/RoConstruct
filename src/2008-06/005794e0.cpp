// from server: 100% by tester
namespace std {
    class bad_cast;
}

typedef void (__thiscall *BadCastConstructor)(std::bad_cast*, const char*);
extern BadCastConstructor importedBadCastConstructor;

namespace std {
    class bad_cast {
        unsigned char storage[12];
    public:
        explicit bad_cast(const char*);
        bad_cast(const bad_cast&);
        ~bad_cast();
    };

    inline bad_cast::bad_cast(const char* message)
    {
        importedBadCastConstructor(this, message);
    }
}

struct Value {
    virtual ~Value();
    virtual void reserved();
    virtual Value* clone() const;
};

struct Argument {
    unsigned long tag;
    Value* value;

    Argument(const Argument&);
    ~Argument();
};

inline Argument::Argument(const Argument& other)
{
    Value* source = other.value;
    tag = other.tag;
    Value* result;
    if (source)
        result = source->clone();
    else
        result = 0;
    value = result;
}

inline Argument::~Argument()
{
    if (value)
        delete value;
}

namespace RBX { namespace Reflection { class DescribedBase {
public:
    virtual ~DescribedBase();
}; } }
using RBX::Reflection::DescribedBase;

namespace RBX { class DataModel : public Reflection::DescribedBase {
}; }
using RBX::DataModel;

struct Arguments {
    virtual void reserved();
    virtual void get(int, Argument*);
};

struct BoundFuncDesc {
    unsigned char padding[64];
    Argument first;
    Argument second;

    void invoke(DescribedBase*, Arguments*);
    void dispatch(DataModel*, void*, const Argument&, const Argument&);
};

void BoundFuncDesc::invoke(DescribedBase* object, Arguments* arguments)
{
    Argument a(first);
    arguments->get(1, &a);

    Argument b(second);
    arguments->get(2, &b);

    DataModel* model = dynamic_cast<DataModel*>(object);
    if (!model)
        throw std::bad_cast("bad cast");

    dispatch(model, reinterpret_cast<char*>(arguments) + 4, a, b);
}
