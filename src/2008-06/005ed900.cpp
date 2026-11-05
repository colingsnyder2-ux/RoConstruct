// from server: 100% by king_originala
struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String();
    ~String();
};

extern void (__thiscall* stringConstructor)(String*);
extern void (__thiscall* stringDestructor)(String*);

__forceinline String::String()
{
    stringConstructor(this);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

struct Name;

struct Value {
    unsigned int name;
    unsigned int type;
    void* data;

    bool isString() const;
    bool getString(String* result) const;
    bool getInteger(int* result) const;
};

struct Element {
    char padding[16];
    Value value;

    bool isNull() const;
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const int* value);
};

struct EnumDescriptor {
    bool convert(const Name& name, int* result);
};

extern void __cdecl initializeEnum();
extern int enumFlag;
extern void __cdecl registerEnum(void (__cdecl* initializer)(), int* flag);
extern EnumDescriptor* __cdecl getEnumDescriptor();
extern const Name& __cdecl getName(const char* text);

struct S {
    char padding[28];
    Setter* setter;

    void read(void* instance, Element* element, int unused);
};

void S::read(void* instance, Element* element, int unused)
{
    if (element->isNull())
        return;

    Value* source = &element->value;
    if (source->isString()) {
        String text;
        if (source->getString(&text)) {
            const char* characters =
                text.capacity >= 16 ? text.pointer : text.buffer;
            registerEnum(initializeEnum, &enumFlag);
            EnumDescriptor* descriptor = getEnumDescriptor();
            int value;
            if (descriptor->convert(getName(characters), &value)) {
                setter->set(instance, &value);
                return;
            }
        }
    }

    int integer;
    if (source->getInteger(&integer)) {
        int converted = integer;
        setter->set(instance, &converted);
    }
}
