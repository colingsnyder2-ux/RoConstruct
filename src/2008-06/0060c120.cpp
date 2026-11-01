// from server: 100% by king_originala
struct String {
    unsigned int pad;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Name;
extern const Name& __cdecl getName(const char*);

struct EnumDescriptor {
    bool lookup(const Name&, int&);
};

enum Value {
    ValueZero = 0
};

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Value&);
};

struct S {
    char padding[0x1c];
    Property* property;
    EnumDescriptor* enumeration;

    bool setString(void*, const String&);
};

bool S::setString(void* object, const String& text)
{
    const char* characters =
        text.capacity >= 16 ? text.storage.pointer : text.storage.buffer;
    EnumDescriptor* descriptor = enumeration;
    int value;
    if (descriptor->lookup(getName(characters), value)) {
        reinterpret_cast<volatile int&>(value) = value;
        property->set(object, reinterpret_cast<const Value&>(value));
        return true;
    }
    return false;
}
