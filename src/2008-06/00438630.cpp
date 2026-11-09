// from server: 100% by king_originala
struct String;

extern const char* (__thiscall *string_c_str)(const String*);

struct Key {
    char padding[4];
    String* unused;
};

struct Item {
    void initialize();
};

struct Collection {
    Item* find(const char*);
};

struct Container {
    char padding[0xE4];
    Collection* collection;
    Item* create(const char*, int);
};

struct S {
    Container* getContainer();
    Item* resolve(const Key*);
};

Item* S::resolve(const Key* key)
{
    const String* text = reinterpret_cast<const String*>(
        reinterpret_cast<const char*>(key) + 4);

    Item* result = getContainer()->collection->find(string_c_str(text));
    if (!result) {
        const char* name = string_c_str(text);
        result = getContainer()->create(name, 0);
        result->initialize();
    }
    return result;
}
