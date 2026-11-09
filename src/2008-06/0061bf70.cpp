// from server: 30% by king_originala
struct String {
    unsigned int allocator;
    union {
        char local[16];
        char* heap;
    } data;
    unsigned int length;
    unsigned int capacity;
    char padding[12];

    String(const String&);
    ~String();
};

struct Shared {
    void* object;
    void* control;

    Shared(const Shared&);
    ~Shared();
};

struct Instance {
    String& name();
    void setParent(Shared);
};

struct Context {
    void* state;
};

struct Error {
    char storage[40];
    Error(const String&);
};

struct Node {
    void* reserved;
    Instance* instance;
};

struct Link {
    void* reserved[2];
    Node* node;
};

struct Handle {
    Link* link;
};

struct Value {
    char storage[12];
    Shared convert();
};

extern "C" Context* __cdecl getContext(Shared*);
extern "C" void __cdecl report(void*, int, const char*, ...);
extern "C" String* __cdecl format(String*, const char*, ...);
extern "C" void __cdecl raiseError(void*, void*);
extern void __fastcall submit(int, Shared);

extern char errorType;

void __cdecl assign(const char* member, Instance* target, Handle* handle,
                    const Shared& parent, const Shared& child,
                    const String& parentName, const String& childName,
                    Value& value, bool allowed, bool converted)
{
    Shared retained(parent);

    if (allowed) {
        {
            String firstName(parentName);
            String secondName(childName);
            Shared temporary(child);
            String& actualName = target->name();
            Context* context = getContext(&temporary);

            const char* first;
            if (firstName.capacity >= 16)
                first = firstName.data.heap;
            else
                first = firstName.data.local;

            const char* second;
            if (actualName.capacity >= 16)
                second = actualName.data.heap;
            else
                second = actualName.data.local;

            report(context->state, 2, "%s should not be a child of %s",
                   second, first);
        }

        target->setParent(retained);
    } else if (converted) {
        submit(3, value.convert());
    } else {
        Instance* instance = handle->link->node->instance;
        String* actualName = reinterpret_cast<String*>(
            reinterpret_cast<char*>(instance) + 4);

        const char* text;
        if (actualName->capacity >= 16)
            text = actualName->data.heap;
        else
            text = actualName->data.local;

        char messageStorage[28];
        String* message = reinterpret_cast<String*>(messageStorage);
        String* formatted = format(message,
                                   "%s is not a valid member of %s",
                                   member, text);
        Error error(*formatted);
        raiseError(&error, &errorType);
    }
}
