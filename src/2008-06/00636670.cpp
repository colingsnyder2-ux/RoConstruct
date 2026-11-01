// from server: 100% by king_originala
extern "C" void (__cdecl* _imp__invalid_parameter_noinfo)();
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct RGB {
    float r, g, b;
};

struct Value {
    virtual ~Value();
};

inline Value::~Value() {}

struct ColorValue : Value {
    RGB color;
    explicit ColorValue(const RGB&);
};

inline ColorValue::ColorValue(const RGB& value) {
    color.r = value.r;
    color.g = value.g;
    color.b = value.b;
}

struct Owner {
    Value* ptr;
    explicit Owner(Value*);
    ~Owner();
    void swap(Owner&);
};

inline Owner::Owner(Value* p) : ptr(p) {}

inline Owner::~Owner() {
    if (ptr)
        delete ptr;
}

inline void Owner::swap(Owner& other) {
    if (this != &other) {
        Value* p = other.ptr;
        other.ptr = ptr;
        ptr = p;
    }
}

struct Values {
    unsigned int prefix[3];
    Owner* first;
    Owner* last;
    Owner* limit;

    explicit Values(unsigned int);
    ~Values();
    Owner& operator[](unsigned int);
};

inline Owner& Values::operator[](unsigned int index) {
    if (index >= static_cast<unsigned int>(last - first))
        _imp__invalid_parameter_noinfo();
    return first[index];
}

struct Product {
    virtual ~Product();
    virtual void set(Values*);
};

struct S {
    Product* product;
    void f(RGB);
};

void S::f(RGB color) {
    Values values(1);
    Owner& slot = values[0];
    {
        Owner replacement(new ColorValue(color));
        replacement.swap(slot);
    }
    product->set(&values);
}
