// from server: 100% by king_originala
struct String
{
    unsigned int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Vector2int16
{
    short x;
    short y;
};

extern bool __cdecl parseVector(const String&, Vector2int16&);

struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Vector2int16&);
};

struct Descriptor
{
    unsigned char padding[24];
    Setter* setter;

    bool setFromString(void*, const String&);
};

bool Descriptor::setFromString(void* object, const String& text)
{
    Vector2int16 value = { 0, 0 };
    if (parseVector(text, value))
    {
        setter->set(object, value);
        return true;
    }
    return false;
}
