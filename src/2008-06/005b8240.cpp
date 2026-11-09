// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void *);
extern void * __cdecl get_type();

struct String
{
    char storage[32];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Product
{
    virtual ~Product();
};

struct FactoryProduct
{
    Product *product;
    FactoryProduct(void *);
    ~FactoryProduct();
    void swap(FactoryProduct &);
};

__forceinline FactoryProduct::~FactoryProduct()
{
    if (product)
        delete product;
}

__forceinline void FactoryProduct::swap(FactoryProduct &other)
{
    if (this != &other)
    {
        Product *p = product;
        product = other.product;
        other.product = p;
    }
}

struct Value
{
    void *type;
    FactoryProduct holder;
    void assign(const String &);
};

__forceinline void Value::assign(const String &s)
{
    type = get_type();
    FactoryProduct &destination = holder;
    FactoryProduct((void *)&s).swap(destination);
}

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual String get(void *);
};

struct Descriptor
{
    char padding[24];
    Accessor *accessor;
    void get(void *, Value &) const;
};

void Descriptor::get(void *object, Value &value) const
{
    value.assign(accessor->get(object));
}
