// from server: 61% by king_originala
struct String;

extern String* (__thiscall* copyString)(String*, const String&);
extern void (__thiscall* destroyString)(String*);

struct String {
    unsigned char storage[28];
    String(const String&);
    ~String();
};

struct Payload {
    String text;
    int value;
    Payload(String, int);
};

struct Product {
    int identifier;
    Payload payload;
    Product(int, const Payload&);
};

inline String::String(const String& source)
{
    copyString(this, source);
}

inline String::~String()
{
    destroyString(this);
}

inline Product::Product(int id, const Payload& source)
    : identifier(id), payload(source)
{
}

Product makeProduct(int identifier, String input)
{
    return Product(identifier, Payload(input, 1));
}
