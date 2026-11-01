// from server: 100% by king_originala
struct Shared
{
    void* object;
    void* control;
    Shared(const Shared&);
    ~Shared();
};

struct Argument
{
    void* object;
    unsigned char storage[12];
    ~Argument();
};

extern Shared __cdecl convert(void*);

struct Item
{
    unsigned char storage[0x5c];

    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
    Item(Shared);
};

struct View;
struct Owner;

struct ViewTable
{
    void* reserved0[83];
    void (__thiscall *attach)(View*, Item*);
    void* reserved1[4];
    void (__thiscall *refresh)(View*);
};

struct View
{
    ViewTable* table;
};

struct OwnerTable
{
    void* reserved[101];
    View* (__thiscall *getView)(Owner*);
};

struct Owner
{
    OwnerTable* table;
    unsigned char storage[0x3c4];
    unsigned char disabled;
};

struct CInstanceExplorer
{
    void update(int, Argument);
};

void CInstanceExplorer::update(int, Argument argument)
{
    Item* item = new Item(convert(argument.object));
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x378);

    View* view = owner->table->getView(owner);
    view->table->attach(view, item);

    if (!owner->disabled)
    {
        view = owner->table->getView(owner);
        view->table->refresh(view);
    }
}
