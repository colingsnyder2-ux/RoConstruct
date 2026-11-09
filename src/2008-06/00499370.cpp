// from server: 100% by king_originala
extern "C" {
    extern void (__thiscall *destroy_string)(void *);
}

struct StringStorage {
    char data[28];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroy_string(this);
}

struct Tail {
    ~Tail();
};

struct S {
    char prefix[8];
    StringStorage text;
    Tail tail;
    ~S();
};

S::~S()
{
}
