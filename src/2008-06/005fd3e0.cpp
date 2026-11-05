// from server: 100% by king_originala
struct String;
struct Property;

struct Value {
    bool get(Property** result);
};

struct Node {
    char padding[8];
    Value value;
};

struct Descriptor {
    Node* find(const void* key);
};

extern const void* propertyKey;
extern "C" bool (__cdecl *stringEquals)(const String&, const char*);

struct Base {
    void changed(Descriptor* descriptor, int argument);
};

struct Tool : Base {
    void changed(Descriptor* descriptor, int argument);
};

void Tool::changed(Descriptor* descriptor, int argument)
{
    Property* property = 0;
    Node* node = descriptor->find(propertyKey);
    if (node && node->value.get(&property)) {
        bool (__cdecl *equals)(const String&, const char*) = stringEquals;
        if (equals(
                *reinterpret_cast<const String*>(
                    reinterpret_cast<const char*>(property) + 4),
                "BackendToolState"))
            return;
        if (equals(
                *reinterpret_cast<const String*>(
                    reinterpret_cast<const char*>(property) + 4),
                "ActivationState"))
            return;
    }
    Base::changed(descriptor, argument);
}
