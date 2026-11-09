// from server: 100% by tester
struct Text {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

struct EnumTable {
    bool lookup(unsigned int key, int* value);
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* instance, const int* value) = 0;
};

extern unsigned char registrationState;
extern void __cdecl initialize();
extern void __cdecl registerInitializer(void (__cdecl* callback)(), void* state);
extern EnumTable* __cdecl getEnumTable();
extern unsigned int __cdecl stringKey(const char* text);

struct Descriptor {
    unsigned char padding[28];
    Setter* setter;

    bool setString(void* instance, const Text& text);
};

bool Descriptor::setString(void* instance, const Text& text)
{
    const char* characters =
        text.capacity >= 16 ? text.pointer : text.buffer;

    registerInitializer(initialize, &registrationState);
    EnumTable* table = getEnumTable();

    int value;
    if (table->lookup(stringKey(characters), &value)) {
        setter->set(instance, &value);
        return true;
    }
    return false;
}
