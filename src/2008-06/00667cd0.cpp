// from server: 100% by king_originala
struct Primary
{
    virtual ~Primary();
};

struct Secondary
{
    virtual ~Secondary();
};

struct StateBase : Primary, Secondary
{
    int m_x;

    int f();
    virtual ~StateBase();
};

struct Signal
{
    void fire(char*, int);
};

struct Registry
{
    Signal* find(void*);
};

extern Registry registry;

struct Jumping : StateBase
{
    virtual ~Jumping();
};

Jumping::~Jumping()
{
    int owner = f();
    void* key = owner ? reinterpret_cast<char*>(owner) + 20 : 0;
    Signal* signal = registry.find(key);
    if (signal)
    {
        char token;
        reinterpret_cast<Signal*>(
            reinterpret_cast<char*>(signal) + 16)->fire(&token, 0);
    }
}
