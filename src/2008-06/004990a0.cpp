// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class C, class Traits, class Alloc> class basic_string;
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern "C" {
    extern void (__thiscall *string_copy)(String*, const String&);
    extern void (__thiscall *string_destroy)(String*);
}

namespace std {
    template<class C, class Traits, class Alloc>
    class basic_string {
        char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };

    template<class C, class Traits, class Alloc>
    __forceinline basic_string<C, Traits, Alloc>::basic_string(
        const basic_string& source)
    {
        string_copy(this, source);
    }

    template<class C, class Traits, class Alloc>
    __forceinline basic_string<C, Traits, Alloc>::~basic_string()
    {
        string_destroy(this);
    }
}

struct Owner {
    char padding[0x1b4];
    void* value;
};

struct Argument {
    String first;
    String second;
    Owner* owner;
};

struct Value {
    void* owner;
    String second;
    String first;

    Value(void*, const String&, const String&);
};

__forceinline Value::Value(void* p, const String& s, const String& f)
    : owner(p), second(s), first(f)
{
}

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    char padding[0x14];
    Node* head;

    Node* allocate(Node*, Node*, const Value&);
    void grow(unsigned int);
};

struct S {
    char padding[0x24];
    List entries;

    void f(const Argument*);
};

void S::f(const Argument* argument)
{
    Value value(argument->owner ? argument->owner->value : 0,
                argument->second, argument->first);

    List* list = &entries;
    Node* head = list->head;
    Node* node = list->allocate(head, head->prev, value);
    list->grow(1);
    head->prev = node;
    node->prev->next = node;
}
