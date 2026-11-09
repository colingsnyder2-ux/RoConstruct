// from server: 100% by king_originala
struct TypeInfo {
    bool operator==(const TypeInfo&) const;
};

extern bool (TypeInfo::*typeInfoEqual)(const TypeInfo&) const;
extern TypeInfo expectedType;

inline bool TypeInfo::operator==(const TypeInfo& other) const
{
    return (this->*typeInfoEqual)(other);
}

struct Descriptor {
    char padding[8];
    TypeInfo* type;
};

struct String {
    char storage[28];
    ~String();
};

extern void (String::*destroyString)();

inline String::~String()
{
    (this->*destroyString)();
}

struct Argument {
    char storage[32];
    Argument(const String*);
    ~Argument();
};

inline Argument::~Argument()
{
    (reinterpret_cast<String*>(this)->*destroyString)();
}

struct Product {
    virtual ~Product();
    char storage[32];
};

struct FactoryProduct {
    Product* product;
    FactoryProduct(void* arg);
    ~FactoryProduct();
    void swap(FactoryProduct& other);
};

inline FactoryProduct::~FactoryProduct()
{
    delete product;
}

inline void FactoryProduct::swap(FactoryProduct& other)
{
    if (this != &other) {
        Product* old = product;
        product = other.product;
        other.product = old;
    }
}

String __cdecl makeString(Product* const*);
Descriptor* __cdecl getDescriptor();

struct S {
    Descriptor* descriptor;
    Product* product;

    void refresh();
    void finish();
};

void S::refresh()
{
    if (expectedType == *descriptor->type) {
        FactoryProduct(&Argument(&makeString(&product))).swap(
            *reinterpret_cast<FactoryProduct*>(&product));
        descriptor = getDescriptor();
    }
    finish();
}
