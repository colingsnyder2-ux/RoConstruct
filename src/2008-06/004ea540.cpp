// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct State
{
    unsigned char storage[0x28];
    State();
};

struct Count
{
    int value;
    Count();
    ~Count();
};

inline Count::Count() : value(0)
{
}

struct Member
{
    Member(int, int, int);
    ~Member();
};

struct Arguments
{
    int first;
    int second;
};

struct Table
{
    int first;
    Count second;
    Member member;
    Table(const Arguments&);
    void set(State*);
    void finish();
};

Table::Table(const Arguments& args)
    : first(0), second(), member(args.first, args.second, 0)
{
    set(new State);
    finish();
}
