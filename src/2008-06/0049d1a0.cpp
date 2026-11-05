// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct S;

struct Storage
{
    S** owner;
    unsigned int reserved[3];
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;

    Storage(S* value);
    ~Storage();
};

struct Tail
{
    unsigned int value;
    unsigned char flag;

    Tail();
};

struct S
{
    Storage storage;
    Tail tail;

    S();
};

inline Storage::Storage(S* value)
    : owner(new S*(value)),
      first(0),
      second(0),
      third(0),
      fourth(0)
{
}

S::S()
    : storage(this), tail()
{
}
