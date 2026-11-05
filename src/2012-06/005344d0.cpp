// from server: 100% by tajop
struct Attributes {
    int a;
    int b;
};

struct FunctionPtr {
    int a;
    int b;
};

const void* getBoolType();

struct Value {
    Value(const bool& v);
    Value(const Value& other);
    ~Value();
    char pad[0x40];
};

struct Item {
    const void* type;
    Value value;
    Item(const bool& v) : type(getBoolType()), value(v) {}
};

struct DefaultValue {
    bool* p;
    DefaultValue(const bool& v) : p(new bool(v)) {}
    ~DefaultValue();
};

struct FuncDescBase {
    FuncDescBase(const char* name, int security, Attributes attributes);
    ~FuncDescBase();
    virtual void invoke();
    char pad[0x2c];
};

struct BoundFuncDesc : FuncDescBase {
    FunctionPtr function;
    DefaultValue defaultValue;
    BoundFuncDesc(FunctionPtr function, const char* name, const char* arg0name, bool arg0default, int security, Attributes attributes);
    virtual void invoke();
    void declareSignature(const char* arg0name, Item item);
};

BoundFuncDesc::BoundFuncDesc(FunctionPtr function, const char* name, const char* arg0name, bool arg0default, int security, Attributes attributes)
    : FuncDescBase(name, security, attributes)
    , function(function)
    , defaultValue(arg0default)
{
    declareSignature(arg0name, Item(arg0default));
}
