// from server: 100% by king_originala
struct Object {
    virtual ~Object();
};

struct Value {
    char storage[0x30];
    ~Value();
};

struct Base {
    virtual ~Base();
    char padding[0x14];
};

struct __declspec(novtable) Descriptor : Base {
    Value value;
    ~Descriptor();
};

struct Owner {
    Object* pointer;
    unsigned int reserved;
    ~Owner();
};

struct __declspec(novtable) S : Descriptor {
    Owner first;
    Owner second;
    ~S();
};

inline Base::~Base()
{
}

inline Descriptor::~Descriptor()
{
}

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

S::~S()
{
}
