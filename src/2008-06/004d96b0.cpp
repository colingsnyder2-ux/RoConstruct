// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Arguments
{
    int first;
    int second;
};

struct Owner
{
    void* second;

    Owner();
    ~Owner();
};

inline Owner::Owner() : second(0) {}

struct Function
{
    Function(int, int, int);
    ~Function();
};

struct Object
{
    unsigned char storage[0x28];

    Object();
};

struct Table
{
    void* first;
    Owner owner;
    Function function;

    Table(const Arguments&);
    void assign(Object*);
    void finish();
};

Table::Table(const Arguments& args)
    : first(0), owner(), function(args.first, args.second, 0)
{
    assign(new Object);
    finish();
}
