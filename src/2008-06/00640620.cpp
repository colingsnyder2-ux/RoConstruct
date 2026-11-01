// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);

struct Base {
    char storage[32];
    ~Base();
};

struct Item {
    ~Item();
};

void __cdecl operator delete(void *);

struct Owner {
    Item *pointer;
    ~Owner();
};

struct String {
    char storage[28];
    ~String();
};

struct VirtualPart {
    virtual ~VirtualPart();
};

struct S : Base {
    Owner owner;
    String text;
    char padding[8];
    VirtualPart part;
    ~S();
};

__forceinline Owner::~Owner()
{
    delete pointer;
}

__forceinline String::~String()
{
    destroyString(this);
}

__forceinline VirtualPart::~VirtualPart()
{
}

S::~S()
{
}
