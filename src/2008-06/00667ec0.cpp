// from server: 100% by king_originala
struct Primary
{
    virtual ~Primary();
};

struct Secondary
{
    virtual ~Secondary();
};

struct Base : Primary, Secondary
{
    int value;
    virtual ~Base();
    void* f();
};

struct Event
{
    void fire(char*, int);
};

struct Registry
{
    void* find(void*);
};

struct S : Base
{
    virtual ~S();
};

S::~S()
{
    void* p = f();
    void* key = p ? static_cast<char*>(p) + 20 : 0;
    void* found = reinterpret_cast<Registry*>(0x0097a630)->find(key);
    if (found)
    {
        char tag;
        reinterpret_cast<Event*>(static_cast<char*>(found) + 16)->fire(&tag, 0);
    }
}
