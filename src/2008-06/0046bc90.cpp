// from server: 100% by Gemini
struct String;
extern void (__thiscall* string_copy_ctor)(String*, const String&);
extern void (__thiscall* string_dtor)(String*);

struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int size;
    unsigned int capacity;

    String(const String&);
    ~String();
};

inline String::String(const String& other) {
    string_copy_ctor(this, other);
}

inline String::~String() {
    string_dtor(this);
}

struct Base {
    virtual ~Base();
};

struct Object : virtual Base {
};

struct Temporary {
    Object* value;
    ~Temporary();
};

inline Temporary::~Temporary() {
    if (value)
        delete value;
}

struct Pointer {
    Object* value;
    Pointer(const Temporary&);
    ~Pointer();
};

inline Pointer::Pointer(const Temporary& other) {
    Object* saved = other.value;
    const_cast<Temporary&>(other).value = 0;
    value = saved;
}

inline Pointer::~Pointer() {
    if (value)
        delete value;
}

struct Argument {
    String text;
    int value;
    Argument(const String&, int);
};

inline Argument::Argument(const String& source, int number)
    : text(source), value(number) {
}

struct Factory {
    Temporary create(Argument);
};

struct Provider {
    Factory* getFactory();
};

struct S {
    unsigned char padding[36];
    Provider* provider;

    Factory* factory();
    void consume(Object*, int);
    void f(Argument, int);
};

inline Factory* S::factory() {
    return provider ? provider->getFactory() : 0;
}

void S::f(Argument arg, int option) {
    Pointer object(factory()->create(arg));
    consume(object.value, option);
}
