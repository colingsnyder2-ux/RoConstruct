// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String {
    unsigned int allocator;
    char buffer[16];
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String(const String&);
    ~String();
};

extern void (__thiscall *copyString)(String*, const String*);
extern void (__thiscall *destroyString)(String*);



__forceinline String::~String()
{
    destroyString(this);
}

struct Node {
    unsigned int data[3];

    Node(String);
    ~Node();
};

struct S {
    char padding[0x174];
    Node* value;

    void set(String text);
};

void S::set(String text)
{
    Node* previous;
    if (text.length == 0) {
        previous = value;
        value = 0;
    } else {
        Node* replacement = new Node(text);
        previous = value;
        value = replacement;
    }
    delete previous;
}
