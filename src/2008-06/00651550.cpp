// from server: 100% by king_originala
void __cdecl operator delete(void *) throw();

struct Allocation {
    void *pointer;
    ~Allocation();
};

struct Storage {
    Allocation allocation;
    unsigned data[4];

    void clear();
    ~Storage();
};

struct S {
    unsigned prefix;
    Storage storage;

    ~S();
};

inline Allocation::~Allocation()
{
    operator delete(pointer);
}

inline Storage::~Storage()
{
    clear();
}

S::~S()
{
}
