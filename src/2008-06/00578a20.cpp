// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

inline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

inline void __cdecl operator delete(void* p, void*)
{
    operator delete(p);
}

bool __cdecl func_0060a2f0();

struct String;
typedef void (__thiscall *StringCopy)(String*, const String&);
typedef void (__thiscall *StringDestroy)(String*);

extern StringCopy stringCopy;
extern StringDestroy stringDestroy;
extern unsigned char tableData[];

struct String
{
    unsigned char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    stringCopy(this, other);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Node
{
    int value;
    String text;
    Node(int, const String&);
};

inline Node::Node(int value_, const String& text_)
    : value(value_), text(text_)
{
}

struct S
{
    void* table;
    unsigned int reserved;
    Node* node;
    S(int, String, int);
};

S::S(int value, String text, int)
{
    table = 0;
    if (!reinterpret_cast<bool (__cdecl *)(const int*)>(
            func_0060a2f0)(&value))
    {
        Node* p = static_cast<Node*>(operator new(sizeof(Node)));
        new (p) Node(value, text);
        node = p;
        table = tableData;
    }
    else
    {
        table = 0;
    }
}
