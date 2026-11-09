// from server: 100% by king_originala
extern "C" void* (__cdecl *allocate)(unsigned int);
extern "C" void __cdecl free(void*);

struct String {
    char storage[28];
    ~String();
};

extern void (__thiscall *destroyString)(String*);

inline String::~String()
{
    destroyString(this);
}

struct Deleter {
    unsigned char unused;
    Deleter();
};

inline Deleter::Deleter() : unused(0)
{
}

struct Node {
    char storage[384];

    Node(void*, const String&);
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
};

inline void* Node::operator new(unsigned int size) throw()
{
    return allocate(size);
}

inline void Node::operator delete(void* p)
{
    free(p);
}

struct Pointer {
    Node* object;
    void* control;

    Pointer(Node*, Deleter);
    ~Pointer();
};

Pointer __cdecl makePointer(void* owner, String name)
{
    Deleter deleter;
    return Pointer(new Node(owner, name), deleter);
}
