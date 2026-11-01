// from server: 100% by king_originala
struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    ~String();
};

extern void (__thiscall *destroyString)(String*);

inline String::~String()
{
    destroyString(this);
}

struct NamedValue {
    unsigned int reserved;
    String name;
};

struct Node {
    unsigned int reserved;
    NamedValue* value;
    Node* next;
};

extern String __cdecl format(const char* pattern, ...);
extern void __cdecl writeString(void* destination, const char* text);

int __cdecl convert(Node** source, void* destination)
{
    Node* node = *source;
    String* first = &node->value->name;
    const char* firstText =
        first->capacity >= 16 ? first->pointer : first->buffer;

    String* second = &node->next->value->name;
    const char* secondText =
        second->capacity >= 16 ? second->pointer : second->buffer;

    String text = format("Enum.%s.%s", secondText, firstText);
    writeString(destination,
                text.capacity >= 16 ? text.pointer : text.buffer);
    return 1;
}
