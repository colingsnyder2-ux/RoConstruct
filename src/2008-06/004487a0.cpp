// from server: 100% by king_originala
struct String;
extern const char* (__thiscall *string_c_str)(const String*);

extern const void* __cdecl internName(const char*);

struct EnumMap {
    bool lookup(const void*, int*);
};

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const int&);
};

struct Descriptor {
    char padding[0x1c];
    Property* property;
    EnumMap* enumMap;

    bool set(void*, const String&);
};

bool Descriptor::set(void* instance, const String& text)
{
    int result;
    const char* name = string_c_str(&text);
    EnumMap* map = enumMap;

    if (map->lookup(internName(name), &result)) {
        *(volatile int*)&result = result;
        property->set(instance, result);
        return true;
    }

    return false;
}
