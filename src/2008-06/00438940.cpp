// from server: 100% by king_originala
struct First
{
    void* first;

    First() : first(0) {}
};

struct Storage
{
    void* last;

    Storage() : last(0) {}
    ~Storage();
};

struct S : First, Storage
{
    void* limit;

    explicit S(unsigned int count);
    void initialize(unsigned int count);
};

S::S(unsigned int count) : First(), Storage(), limit(0)
{
    initialize(count);
}
