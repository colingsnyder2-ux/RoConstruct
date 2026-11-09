// from server: 100% by king_originala
struct String {
    char storage[28];
};

struct Value {
    int reserved;
    String text;
};

struct Source {
    virtual void unused();
    virtual Value* get();
};

extern void (__thiscall *copyString)(String*, const String*);

struct InsertDecal {
    char reserved[16];
    Source source;
    String* f(String* result);
};

String* InsertDecal::f(String* result) {
    volatile int temporary = 0;
    Value* value = source.get();
    copyString(result, &value->text);
    return result;
}
