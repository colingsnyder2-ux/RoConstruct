// from server: 100% by king_originala
void* operator new(unsigned int);

extern void* func_00491360();
extern void* func_0056cc30();
extern void* func_00594a50();
extern void* __cdecl func_00553f90(int, int);

struct Holder;

struct Descriptor
{
    void* value;
    void func_00594b40(void*, void*, Holder*);
};

struct Base
{
    virtual ~Base();
    char reserved0[16];
    Descriptor descriptor;
    char reserved1[32];

    Base(void*, int, int);
};

struct Action
{
    virtual ~Action();
    bool flag;

    Action(bool);
};

inline Action::Action(bool value) : flag(value)
{
}

struct Holder
{
    void* type;
    Action* action;

    Holder(bool);
    ~Holder();
};

inline Holder::Holder(bool flag)
    : type(func_0056cc30()), action(new Action(flag))
{
}

struct S : Base
{
    int first;
    int second;
    Holder holder;

    S(int, int, int, int, bool, int);
    virtual ~S();
};

S::S(int a, int b, int c, int d, bool flag, int e)
    : Base(func_00491360(), c, e),
      first(a),
      second(b),
      holder(flag)
{
    descriptor.value = func_00594a50();
    descriptor.func_00594b40(
        func_00553f90(d, -1), func_0056cc30(), &holder);
}
