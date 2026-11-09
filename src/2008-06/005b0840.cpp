// from server: 100% by king_originala
struct String {};

struct Object {
    unsigned char prefix[4];
    String text;
};

struct Value {
    bool extract(Object** result);
};

struct Node {
    unsigned char prefix[8];
    Value value;
};

struct Descriptor {
    Node* lookup(void* key);
};

struct Accoutrement {
    void fallback(Descriptor* descriptor, void* argument);
    void update(Descriptor* descriptor, void* argument);
};

typedef bool (__cdecl *StringEqual)(const String&, const char*);

extern void* lookupKey;
extern StringEqual stringEqual;
extern const char backendState[];

void Accoutrement::update(Descriptor* descriptor, void* argument)
{
    Object* object = 0;
    Node* node = descriptor->lookup(lookupKey);

    if (node && node->value.extract(&object)) {
        if (stringEqual(object->text, backendState))
            return;
    }

    fallback(descriptor, argument);
}
