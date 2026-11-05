// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
void __cdecl operator delete(void*, void*);

__forceinline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

struct Text {
    char data[24];
    Text(const Text&);
};

struct Value {
    int id;
    Text text;
};

struct Item {
    Item* first;
    Item* second;
    Item* third;
    Value value;
    bool flag;
    bool extra;

    Item(Item*, Item*, Item*, const Value&, bool);
};

__forceinline Item::Item(Item* a, Item* b, Item* c,
                        const Value& v, bool f)
    : first(a), second(b), third(c), value(v), flag(f), extra(false)
{
}

Item* __stdcall createItem(Item* a, Item* b, Item* c,
                          const Value& v, bool f)
{
    Item* p = static_cast<Item*>(operator new(sizeof(Item)));
    try {
        new (p) Item(a, b, c, v, f);
    } catch (...) {
        operator delete(p);
        throw;
    }
    return p;
}
