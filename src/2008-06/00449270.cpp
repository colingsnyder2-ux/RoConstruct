// from server: 100% by king_originala
struct String {};

extern bool (__cdecl *stringNotEqual)(const String&, const String&);
extern String& (__thiscall *stringAssign)(String*, const String&);

struct Object {
    void changed(void*);
};

struct Property {
    int reserved;
    void* descriptor;
    int valueOffset;
    int unused;
    void (__thiscall *notify)(void*, void*);
    int notifyOffset;

    void set(void* instance, const String& value);
};

void Property::set(void* instance, const String& value)
{
    Object* object = instance
        ? reinterpret_cast<Object*>(static_cast<char*>(instance) - 20)
        : 0;

    if (stringNotEqual(
            *reinterpret_cast<String*>(
                reinterpret_cast<char*>(object) + valueOffset),
            value)) {
        stringAssign(
            reinterpret_cast<String*>(
                reinterpret_cast<char*>(object) + valueOffset),
            value);

        if (notify)
            notify(reinterpret_cast<char*>(object) + notifyOffset,
                   descriptor);

        object->changed(descriptor);
    }
}
