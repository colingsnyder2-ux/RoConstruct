// from server: 100% by EspClaude


struct String
{
    unsigned int proxy;
    union { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
    const char* c_str() const { const char* p = storage.pointer; if (capacity < 16) p = storage.buffer; return p; }
    unsigned int size() const { return length; }
};

struct Name;
extern const Name& __cdecl lookupName(const char*);

enum EnumValue
{
    EnumValueZero = 0
};

struct Value
{
    bool isString() const;
    bool getString(String&) const;
    bool getInteger(int&) const;
};

struct Element
{
    char padding[16];
    Value value;
    bool isNull() const;
};

struct EnumDescriptor
{
    bool convert(const Name&, int&) const;
};

struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const EnumValue&);
};

struct S
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual bool setEmpty(void*, int);

    char padding[24];
    Setter* setter;
    EnumDescriptor* descriptor;

    void read(void*, Element*, int);
    void setValue(void* o, EnumValue value) { setter->set(o, value); }
    __forceinline bool convertToValue(const char* text, EnumValue& value) { EnumDescriptor* d = descriptor; int v; if (d->convert(lookupName(text), v)) { value = (EnumValue)v; return true; } return false; }
};

void S::read(void* object, Element* element, int)
{
    if (element->isNull())
        return;
    if (element->value.isString())
    {
        String text;
        if (element->value.getString(text))
        {
            EnumValue val;
            if (convertToValue(text.c_str(), val))
            {
                setValue(object, val);
                return;
            }
            if (text.size() == 0 && setEmpty(object, 0))
                return;
        }
    }
    int value;
    if (element->value.getInteger(value))
        setValue(object, (EnumValue)value);
}
