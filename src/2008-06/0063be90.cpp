// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

extern const char serviceName[];
extern unsigned int table0[], table10[], table14[], table20[];
extern unsigned int table24[], table44[], table64[], table84[];
extern unsigned int tableA4[], tableC4[];

struct Base
{
    unsigned int data[76];
    Base(const char*);
    ~Base();
};

struct Node
{
    void* owner;
    Node(void*);
};

inline Node::Node(void* p) : owner(p)
{
}

struct Container
{
    Node* head;
    unsigned int reserved[3];
    unsigned int count;
    unsigned int capacity;
    unsigned int first;
    unsigned int last;

    void initialize();
};

inline void Container::initialize()
{
    head = new Node(this);
    count = 0;
    capacity = 0;
    first = 0;
    last = 0;
}

struct S : Base
{
    Container container;
    int maxItems;
    unsigned int pending;

    S();
};

S::S() : Base(serviceName)
{
    data[0] = reinterpret_cast<unsigned int>(table0);
    data[4] = reinterpret_cast<unsigned int>(table10);
    data[5] = reinterpret_cast<unsigned int>(table14);
    data[8] = reinterpret_cast<unsigned int>(table20);
    data[9] = reinterpret_cast<unsigned int>(table24);
    data[17] = reinterpret_cast<unsigned int>(table44);
    data[25] = reinterpret_cast<unsigned int>(table64);
    data[33] = reinterpret_cast<unsigned int>(table84);
    data[41] = reinterpret_cast<unsigned int>(tableA4);
    data[49] = reinterpret_cast<unsigned int>(tableC4);

    container.initialize();
    pending = 0;
    maxItems = 300;
}
