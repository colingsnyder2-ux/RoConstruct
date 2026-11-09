// from server: 100% by king_originala
struct String {
    unsigned char data[28];
};

extern String& (__thiscall *assignString)(String*, const String&);

struct Texture {
    unsigned char data[12];
    Texture();
    ~Texture();
};

extern void (__thiscall *constructTexture)(Texture*);

__forceinline Texture::Texture()
{
    constructTexture(this);
}

struct Base {
    virtual ~Base();
    unsigned char reserved[8];
    String name;
    unsigned char tail[8];
    Base();
};

struct Value {
    int value;
    Value(int);
    ~Value();
};

__forceinline Value::Value(int initial)
    : value(initial)
{
}

struct Auxiliary {
    unsigned char data[8];
    ~Auxiliary();
};

struct State {
    void* first;
    void* second;
    unsigned char reserved[12];
    State();
    ~State();
};

__forceinline State::State()
    : first(0), second(0)
{
}

struct S : Base {
    Value type;
    bool flag;
    unsigned char padding[3];
    Auxiliary auxiliary;
    State state;
    Texture texture;

    S(const String& source);
    virtual ~S();
};

S::S(const String& source)
    : type(0), flag(false)
{
    assignString(&name, source);
}
