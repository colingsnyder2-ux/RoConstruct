// from server: 100% by king_originala
extern void (__thiscall* stringConstruct)(void*);
extern void (__thiscall* stringDestroy)(void*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned int allocatorStorage;
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;
    public:
        basic_string();
        ~basic_string();
        const T* c_str() const;
    };

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::basic_string()
    {
        stringConstruct(this);
    }

    template<class T, class Traits, class Alloc>
    inline basic_string<T, Traits, Alloc>::~basic_string()
    {
        stringDestroy(this);
    }

    template<class T, class Traits, class Alloc>
    inline const T* basic_string<T, Traits, Alloc>::c_str() const
    {
        const T* result = storage.pointer;
        if (capacity < 16)
            result = storage.buffer;
        return result;
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Name;
enum EnumValue { EnumValueZero = 0 };

struct Value {
    bool isString() const;
    bool getString(String*) const;
    bool getInteger(int*) const;
};

struct Element {
    char padding[16];
    Value value;
    bool isNull() const;
};

struct EnumDescriptor {
    bool parse(const Name&, EnumValue*) const;
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const EnumValue*);
};

extern void __cdecl initializeEnum();
extern int enumRegistration;
extern void __cdecl registerEnum(void (__cdecl*)(), int*);
extern EnumDescriptor* __cdecl getEnumDescriptor();
extern const Name& __cdecl lookupName(const char*);

struct S {
    char padding[28];
    Setter* setter;
    void read(void*, Element*, void*);
};

void S::read(void* instance, Element* element, void*)
{
    if (element->isNull())
        return;

    Value& data = element->value;
    if (data.isString()) {
        String text;
        if (data.getString(&text)) {
            const char* characters = text.c_str();
            registerEnum(initializeEnum, &enumRegistration);
            EnumDescriptor* descriptor = getEnumDescriptor();
            EnumValue value;
            if (descriptor->parse(lookupName(characters), &value)) {
                setter->set(instance, &value);
                return;
            }
        }
    }

    int integer;
    if (data.getInteger(&integer)) {
        EnumValue converted = static_cast<EnumValue>(integer);
        setter->set(instance, &converted);
    }
}
