// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2009-06 0063ff80  unit: RBX::Accoutrement  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063ff80
//

// from server: 100% by coldek
// roc 2008-06 005b4410  unit: RBX::VHat::?$FactoryProduct  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b4410
//

struct String;

extern String* (__thiscall *string_copy)(String*, const String&);
extern void (__thiscall *string_destroy)(String*);

struct String {
    unsigned char data[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    string_copy(this, other);
}

inline String::~String()
{
    string_destroy(this);
}

struct Color {
    unsigned char r, g, b, a;
};

struct FloatColor {
    float r, g, b, a;
    FloatColor(const Color*);
    FloatColor(const FloatColor&);
};

inline FloatColor::FloatColor(const FloatColor& other)
    : r(other.r), g(other.g), b(other.b), a(other.a)
{
}

struct ColorEntry {
    int key;
    Color value;
};

struct FloatEntry {
    int key;
    FloatColor value;
    FloatEntry(int, const FloatColor&);
};

inline FloatEntry::FloatEntry(int k, const FloatColor& v)
    : key(k), value(v)
{
}

struct StringEntry {
    int key;
    String value;
    StringEntry(int, const String&);
};

inline StringEntry::StringEntry(int k, const String& v)
    : key(k), value(v)
{
}

struct InsertResult {
    void* position;
    bool inserted;
    InsertResult(const InsertResult&);
};

struct ColorMap {
    unsigned char data[32];
    InsertResult insert(const ColorEntry&);
};

struct FloatMap {
    unsigned char data[32];
    InsertResult insert(const FloatEntry&);
};

struct StringMap {
    unsigned char data[32];
    InsertResult insert(const StringEntry&);
};

struct S {
    unsigned char data[72];
    ColorMap colors;
    FloatMap floats;
    StringMap strings;

    void prepare(const int*);
    void f(int, unsigned char, unsigned char, unsigned char, String);
};

inline FloatColor convert(const Color* c)
{
    FloatColor converted(c);
    return converted;
}

void S::f(int key, unsigned char r, unsigned char g,
          unsigned char b, String text)
{
    Color color;
    color.r = r;
    color.g = g;
    color.a = 0;
    color.b = b;

    *reinterpret_cast<int*>(&r) = key;
    prepare(reinterpret_cast<const int*>(&r));

    {
        ColorEntry entry;
        entry.key = key;
        entry.value = color;
        colors.insert(entry);
    }

    {
        FloatEntry entry(key, convert(&color));
        floats.insert(entry);
    }

    StringEntry entry(key, text);
    strings.insert(StringEntry(entry.key, entry.value));
}
