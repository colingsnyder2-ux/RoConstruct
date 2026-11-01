// from server: 100% by colin
struct String
{
    const char* c_str() const;
};

extern const char* (__thiscall *stringData)(const String*);

__forceinline const char* String::c_str() const
{
    return stringData(this);
}

struct Holder
{
    char pad[4];
    String text;
};

struct Item
{
    virtual void unused();
    virtual bool value();
    Holder* holder;
};

inline const char* NameText(const Holder* n, const Holder*) { return n->text.c_str(); }

struct Base
{
    void* table;
    char pad04[0x1c];
    void* secondaryTable;
    char pad24[0xd8];
    int kind;
    char pad100[0x0c];

    Base(const char*, int, int);
    ~Base();
    void OnValueChanged(int);
};

struct Member
{
    void* table;
    char pad[0x1c];

    Member(Item*, int);
    ~Member();
};

extern void* primaryTable[];
extern void* secondaryTable[];
extern void* memberTable[];

struct S : Base
{
    Member member;
    Item* item;

    S(Item*, int);
};

S::S(Item* source, int argument)
    : Base(NameText(source->holder, source->holder), 0, 0),
      member(source, argument)
{
    kind = 1;
    table = primaryTable;
    secondaryTable = ::secondaryTable;
    member.table = memberTable;
    item = source;
    OnValueChanged(source->value());
}
