// from server: 100% by king_originala
struct Base
{
    virtual ~Base();
};

struct Interface
{
    virtual void unused() = 0;
};

struct Getter
{
    char padding[8];
    int value;
    int f();
};

struct Event
{
    void invoke(char*, int);
};

struct Lookup
{
    char* find(void*);
};

extern Lookup lookup;

struct S : Base, Interface
{
    virtual ~S();
};

S::~S()
{
    int object = reinterpret_cast<Getter*>(this)->f();
    void* key = object ? reinterpret_cast<void*>(object + 0x14) : 0;
    char* result = lookup.find(key);

    if (result)
    {
        char temporary;
        reinterpret_cast<Event*>(result + 0x10)->invoke(&temporary, 0);
    }
}
