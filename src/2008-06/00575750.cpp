// from server: 100% by colin
struct Item;
struct String;

extern void* (__thiscall* string_construct)(String*, const char*);
extern int (__thiscall* string_compare)(
    const String*, unsigned int, unsigned int, const char*, unsigned int);

struct String {
    char storage[20];
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String(const char*);
    String(const String&);
    ~String();
    int compare(unsigned int, unsigned int, const char*, unsigned int) const;
};

inline int String::compare(unsigned int pos, unsigned int count,
                           const char* text, unsigned int size) const {
    return string_compare(this, pos, count, text, size);
}

struct Name {
    char padding[4];
    String text;
};

struct NameSource {
    virtual void slot0();
    virtual Name* getName();
};

struct Item {
    char padding[0x10];
    NameSource source;
};

struct Verb {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void invoke(int);
};

struct Lookup {
    char storage[0x3c];
    Verb* find(String);
};

struct Controller {
    void f();
};

struct S {
    char padding[0x1c8];
    Lookup lookup;
    Controller* controller;

    void baseCall(Item*);
    void f(Item*);
};

void S::f(Item* item) {
    baseCall(item);
    String* text = &item->source.getName()->text;
    if (text->compare(0, text->length, "NetworkClient", 13) == 0) {
        Verb* verb = lookup.find(String("LockPlayMode"));
        if (verb)
            verb->invoke(0);
        controller->f();
    }
}
